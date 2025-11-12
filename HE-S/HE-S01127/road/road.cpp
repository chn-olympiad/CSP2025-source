#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+5;
struct node1{
	int v,w;
};
vector<node1> a[MAXN];
struct node2{
	int c;
	int a[MAXN];
}b[15];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].push_back((node1){v,w});
	}
	for(int i=1;i<=k;i++){
		cin>>b[i].c;
		for(int j=1;j<=n;j++){
			cin>>b[i].a[j];
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int minw=INT_MAX,len=a[i].size();
			for(int k=0;k<len;k++){
				if(a[i][k].v==j&&a[i][k].w<minw) {
					minw=a[i][k].w;
				}
			}
			ans+=minw;
		}
	}
	cout<<ans;
	return 0;
}
