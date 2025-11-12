#include<bits/stdc++.h>
#define N 5020
const int Mod = 998244353;
using namespace std;
int n,ans,a[N],sum[N][N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	memset(sum,0,sizeof sum);
	ios::sync_with_stdio(0);
	cin>>n;
	sum[0][0]=1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	  for(int l=0;l<=5001;l++)
	    if(sum[i-1][l])
		  {
		  	sum[i][min(5001,(l+a[i]))]=(sum[i][min(5001,l+a[i])]+sum[i-1][l])%Mod;
			sum[i][l]=(sum[i][l]+sum[i-1][l])%Mod;
		  }
	for(int i=1;i<=n;i++)
	  for(int l=5001;l>=0;l--)
	    sum[i][l]=(sum[i][l+1]%Mod+sum[i][l]%Mod)%Mod;
	for(int i=n;i>=3;i--)
	  ans=(ans+(sum[i-1][a[i]+1])%Mod)%Mod;
	cout<<ans;
	return 0;
}
