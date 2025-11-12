#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10,Mod=998244353;
int f[N][2*N],n,a[N],mx,res;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		mx=max(mx,a[i]);
	} 
	sort(a+1,a+1+n);
	f[0][0]=1;
	for(int i=0;i<n;i++) 
	{
		for(int j=a[i+1]+1;j<=2*mx+5;j++) res=(res+f[i][j])%Mod;
		for(int j=0;j<=2*mx+5;j++) 
		{
			f[i+1][j]=(f[i+1][j]+f[i][j])%Mod;
			f[i+1][min(2*mx+5,j+a[i+1])]=(f[i+1][min(2*mx+5,j+a[i+1])]+f[i][j])%Mod;
		}
	} 
	printf("%d",res);
	return 0;
} 