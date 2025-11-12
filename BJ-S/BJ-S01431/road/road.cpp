#include<bits/stdc++.h>
using namespace std;
long long a[11451][11451];
long long b[11451],p;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	memset(a,-1,sizeof(a));
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		a[u][v]=w;
		a[v][u]=w;
	}
	for(int i=1;i<=k;i++){
		long long x,f[11451];
		memset(f,0,sizeof(f));
		cin>>x;
		for(int j=1;j<=n;j++)cin>>f[j];
		for(int g=1;g<=n;g++){
			for(int h=g;h<=n;h++){
				long long r=x+f[g]+f[h];
				if((r<a[g][h]||a[g][h]==-1)&&g!=h)a[g][h]=a[h][g]=r;
			}
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=i;j<=n;j++)
			if(a[i][j]!=-1){
				b[++p]=a[i][j];
			}
	sort(b+1,b+p+1);
	long long sum=0;
	for(long long i=1;i<n;i++)sum+=b[i];
	cout<<sum;
	return 0;
}
