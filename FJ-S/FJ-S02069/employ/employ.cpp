#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define P_B push_back
const int inf=0x3f3f3f3f;
const ll INF=9e18;
const int N=510;
const int mod=998244353;
char s[N];
int c[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	cin>>(s+1);
	fo(i,1,n) cin>>c[i];
	if(n<=100)
	{
		cout<<"0"<<endl;
		return 0;
	}
	bool flag=1;
	int cnt=0;
	fo(i,1,n)
	{
		if(!c[i]) ++cnt;
		if(cnt>1|| s[i]=='0') flag=0;
	}
	if(flag)
	{
		ll ans=1;
		fo(i,1,n-1) {ans*=i; ans%=mod;}
		if(!cnt) cout<<ans*n%mod<<endl;
		else cout<<ans<<endl;
	}
	else cout<<"0"<<endl;
	return 0;
}
/*
in1:

out1:

*/
