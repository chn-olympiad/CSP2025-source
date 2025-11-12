#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10,K=16;
const long long inf=1e18;
long long n,m,k,ans;
long long f[N][N],c[K][N];
bool o=true;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(n==1){
		cout<<0<<endl;
		return 0;
	}1
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n+k;j++){
			f[i][j]=i==j?0:inf;
		}
	}
	for(long long i=1,u,v,w;i<=n;i++){
		cin>>u>>v>>w;
		f[u][v]=f[v][u]=min(f[u][v],w); 
	}
	for(int i=1,x;i<=k;i++){
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			f[n+i][j]=f[j][n+i]=c[i][j];
			if(o&&x==0&&c[i][j]==0){
				o=true;
			}else{
				o=false;
			}
		}
		if(o){
			cout<<0<<endl;
			return 0;
		} 
	}
	for(int l=1;l<=n+k;l++){
		for(int i=1;i<=n+k;i++){
			for(int j=1;j<=n+k;j++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][l]+f[l][j]);
			}
		}
	} 
	for(int i=1;i<=n;i++){
		long long l=inf;
		for(int j=1;j<=n;j++){
			if(i!=j) l=min(l,f[i][j]);
		}
		ans+=l;
	}
	cout<<ans<<endl;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
