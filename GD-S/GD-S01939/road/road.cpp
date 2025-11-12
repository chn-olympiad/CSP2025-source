#include<bits/stdc++.h>
#define ad(k) (k=-~k)
#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
#define D(i,a,b) for(register int i=a;i>=b;i=~-i)
#define min(a,b) (a<b?a:b)
using namespace std;const int N=1e4+1,M=1e6+1;
int n,m,k,u[M],v[M],w[M],a[11][N],c[11],mina[N],sum[11],ans;
int main(){
	freopen("road.in","r",stdin),freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(mina,0x7f,sizeof mina);
	F(i,1,m){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
		mina[u[i]]=min(mina[u[i]],w[i]),mina[v[i]]=min(mina[v[i]],w[i]);
	}F(i,1,k){
		cin>>c[i];
		F(j,1,n){cin>>a[i][j];sum[i]+=a[i][j];}
	}
	F(i,1,k){
		if(sum[i]>ans)continue;
		int suma=c[i];
		F(j,1,n)suma+=min(mina[j],a[i][j]);
		ans=min(ans,suma);
	}cout<<ans;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
