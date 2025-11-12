#include<bits/stdc++.h>
using namespace std;
int n,m,k,l[1000010];
int a;
long long ans;
struct node{
	int v,w;
};
vector<node> g[10100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	for(int i=0;i<k;i++){
		int cnt=0x3f3f3f3f;
		for(int j=0;j<n;j++){
			cin>>a;
			cnt=min(cnt,a);
		}
		ans+=cnt;
	}
	cout<<ans;
	return 0;
}
