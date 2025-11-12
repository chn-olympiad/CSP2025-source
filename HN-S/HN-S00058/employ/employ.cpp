#include<bits/stdc++.h>
#define rep(i,l,r,k) for(int i=l;i<=r;i+=k)
#define rrep(i,r,l,k) for(int i=r;i>=l;i-=k)
#define loop(i,st,ed,nxt) for(int i=st;i!=ed;i=nxt)
#define int long long
using namespace std;
const int N=505,mod=998244353;
int a[N],b[N];
void init()
{

}
void solve()
{
	int n,m,ans=0;
	string s;
	cin>>n>>m>>s;s="#"+s; 
	rep(i,1,n,1)cin>>a[i];
	if(n<=10)
	{
		rep(i,1,n,1)b[i]=i;
		do
		{
			int cnt=0,res=0;
			rep(i,1,n,1)
			{
				if(s[i]=='0'||cnt>=a[b[i]])++cnt;
				else ++res;
			}
//			cout<<res<<'\n';
			if(res>=m)++ans;
		}
		while(next_permutation(b+1,b+n+1));
		cout<<ans%mod;
	}
	else
	{
		ans=1;
		rep(i,1,n,1)ans=ans*i%mod;
		cout<<ans;
	}
}
signed main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T=1;
	//cin>>T;
	init();
	rep(i,1,T,1)
	{
		solve();
	}
	return 0; 
}

