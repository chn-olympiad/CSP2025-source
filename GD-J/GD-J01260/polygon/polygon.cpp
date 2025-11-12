#include<bits/stdc++.h>
using namespace std;
const int N=5010,mod=998244353;
int n,mx,now,a[N];
long long ans,f[2][2*N][2];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n),mx=a[n];
	f[0][0][0]=1,now=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=2*mx+1;j++){
			long long x=f[now][j][0]+f[now][j][1];
			if(x>mod) x-=mod;
			f[now^1][j][0]=(f[now^1][j][0]+x)%mod; 
			f[now^1][min(2*mx+1,j+a[i+1])][1]=(f[now^1][min(2*mx+1,j+a[i+1])][1]+x)%mod;
			if(i>0&&j>2*a[i]) ans=(ans+f[now][j][1])%mod;
			f[now][j][0]=f[now][j][1]=0;
		}
		now^=1;
	}
	for(int j=0;j<=2*mx+1;j++)
	  if(j>2*a[n]) ans=(ans+f[now][j][1])%mod;
	cout<<ans;
	return 0; 
}
