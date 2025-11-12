#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(a,b,c) for(int a=b;a<=c;++a)
#define dep(a,b,c) for(int a=b;a>=c;--a)
const int N = 507; const int mod = 998244353;
int n,m,s[N],c[N],t[N],p[N],book[N],ans=0,tot=0; string ss;
int initA=1,A[N];
inline bool Check()//O(n)
{
	int sum=0,qian=0;
	rep(i,1,tot)
	{
		qian=t[i]-1-sum;
		if(qian<c[book[i]]) sum++;
	}
	if(sum>=m) return true;
	return false;
}
inline void dfs(int x)//3.6*10^6
{
	if(x==tot+1)
	{
		if(Check()==true) ans=(ans+initA)%mod;
		return;
	}
	rep(i,1,n)
	    if(p[i]==0)
	    {
			p[i]=1;
			book[x]=i;
			dfs(x+1);
			p[i]=0;
		}
}
inline void init()
{
	A[1]=1;
	rep(i,2,n) A[i]=(A[i-1]*i)%mod;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m; cin>>ss; rep(i,1,n) cin>>c[i];
	for(int i=0;i<n;i++) s[i+1]=ss[i]-'0';
	sort(c+1,c+n+1);
	rep(i,1,n) if(s[i]==1) t[++tot]=i;
	if(n<=10)
	{
	    rep(i,1,n-tot) initA=(initA*i)%mod;
    	dfs(1);//8 pts
	    cout<<ans;
	    return 0;
    }
    if(m==1)
    {
		init(); c[n+1]=mod+1;
		int now=0,lj=1;
		rep(i,1,tot)
		{
			while(c[now+1]<=t[i]-1) now++;
			ans=(ans+ ( (lj*A[n-i])%mod *(n-now) )%mod )%mod;
			lj=(lj* (now-(i-1)) )%mod;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
