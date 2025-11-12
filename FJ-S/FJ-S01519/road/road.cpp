#include<bits/stdc++.h>
using namespace std;
int n,m,k,w[1000005];
vector<int> dl[1000015],c[15]; 
long long ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
		dl[u].push_back(v);
		dl[v].push_back(u);
		ans+=w[i];
	}
	int a;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++){
			cin>>a;
			c[i].push_back(a);
			if(a==0){
				dl[i+n].push_back(j);
				dl[j].push_back(i+n);
			}
		}
	cout<<ans<<endl;
	return 0;
} 
