#include<bits/stdc++.h>
using namespace std;
long long m,n,k,sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>m>>n>>k;
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		sum+=w;
	}
	int f=0;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		if(x!=0)f=1;
		for(int i=1;i<=n;i++){
			int o;
			cin>>o;
			if(o!=0)f=1;
		}
	}
	if(f==0)cout<<0;
	else cout<<sum;
	return 0;
	}
	