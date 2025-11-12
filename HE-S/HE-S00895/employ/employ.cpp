#include"bits/stdc++.h"
using namespace std;
const int maxn = 510;
const int mo = 998244353;
int n,W,m,p[maxn],c[maxn],Su[maxn],Pw[maxn];
int f[maxn][maxn][maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(nullptr);
	cin>>n>>W,Pw[0]=1;
	for(int i=1;i<=n;i++)
		Pw[i]=1ll*Pw[i-1]*i%mo;
	for(int i=1;i<=n;i++){
		char T;
		cin>>T;
		if(T=='1')p[++m]=i;
	}
	for(int i=1,T;i<=n;i++){
		cin>>T;
		Su[T]++;
	}
	for(int i=1;i<=n;i++)
		Su[i]+=Su[i-1];
	f[0][0][0]=1;
	for(int i=1;i<=m;i++)
		for(int j=0;j<i;j++)
			for(int k=0;k<=Su[p[i]-j-1];k++){
				f[i][j+1][k]=(f[i][j+1][k]+f[i-1][j][k])%mo;
				f[i][j+1][k+1]=(f[i][j+1][k+1]-1ll*f[i-1][j][k]*(Su[p[i]-j-1]-k)%mo+mo)%mo;
				f[i][j][k+1]=(f[i][j][k+1]+1ll*f[i-1][j][k]*(Su[p[i]-j-1]-k)%mo)%mo;
			}
	int Ans=0;
	for(int j=W;j<=m;j++)
		for(int k=0;k<=n;k++)
			Ans=(Ans+1ll*f[m][j][k]*Pw[n-k])%mo;
	cout<<Ans<<'\n';
}
