//GZ-S00073 安顺市第一高级中学 卢子墨 
#include<bits/stdc++.h>
#define MAXN 10000

using namespace std;

long long a[MAXN][MAXN],b[MAXN],ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(long long i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		ans+=w;
		a[u][v]=w;
	}
	for(long long i=1;i<=k;i++){
		long long c;
		cin>>c;
		for(long long i=1;i<=n;i++){
			cin>>b[i];
		}
	}
	
	
	
	cout<<ans<<endl;
	
	return 0;
} 
