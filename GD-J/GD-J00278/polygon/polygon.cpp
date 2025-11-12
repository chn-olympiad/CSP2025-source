#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define ir(i,a,b) for(int i=b;i>=a;i--)
#define ll long long
using namespace std;
const int P=998244353,maxn=5114;
ll a[maxn],f[maxn*3],s[maxn*3];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0)->sync_with_stdio(0);
	int n;
	ll ans=0;
	cin>>n;
	rep(i,1,n) cin>>a[i];
	f[0]=1;
	sort(a+1,a+n+1);
	rep(i,1,n)
	{
		s[0]=f[0];
		rep(t,1,15001) s[t]=(s[t-1]+f[t])%P;
		ans=(ans+P+s[15001]-s[a[i]])%P;
		ir(t,0,15001)
		{
			f[min(15001ll,t+a[i])]=(f[min(15001ll,t+a[i])]+f[t])%P;
		}
	}
	cout<<ans;
	return 0;
}
/*
T1 9:13
T2 9:28
T3 9:43
T4 10:14
ËÆºõAKÁË 
Meow! --1443133
*/
