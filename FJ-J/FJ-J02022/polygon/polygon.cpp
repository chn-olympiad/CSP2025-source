#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5001,MOD=998244353,inf=0x3f3f3f3f;
ll a[N],f[N][2*N],e,m,l2[N],s[2*N];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;l2[0]=1;
	for(int i=1;i<=n;i++) cin>>a[i],m=max(m,a[i]),l2[i]=l2[i-1]*2%MOD;
	for(int i=0;i<=2*m;i++) f[0][i]=1,s[i]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<=2*m;j++) f[i][j]=s[j-a[i]];
		for(int j=a[i];j<=2*m;j++) s[j]=(s[j]+f[i][j])%MOD;
	}
	for(int i=3;i<=n;i++) e=(e+l2[i-1]-f[i][2*a[i]])%MOD;
	cout<<e<<endl;
	return 0;
}
