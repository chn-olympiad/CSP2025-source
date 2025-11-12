#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5010,mod=998244353;
ll s[N][N];
ll a[N];
ll n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	s[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=5001;j++)
		{
			s[i][j]+=s[i-1][j],s[i][j]%=mod;
			s[i][min(5001ll,j+a[i])]+=s[i-1][j];
			s[i][min(5001ll,j+a[i])]%=mod;
		}
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=a[i]+1;j<=5001;j++)
			ans=(ans+s[i-1][j])%mod;
	cout<<ans;
	return 0;
}
/*
//freopen
//freopen
froepen
freoepn
#include<bits\stdc++.h> 
x0 y0 x1 y1
signed main() 
*/
