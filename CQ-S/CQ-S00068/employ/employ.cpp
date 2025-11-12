#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define rep1(i,l,r) for(int i=l;i<=r;++i)
#define rep2(i,l,r) for(int i=l;i>=r;--i)
#define rep3(i,h,x,ne) for(int i=h[x];~i;i=ne[i])
#define rep4(x,v) for(auto x:v)
const int N=1e5+10;
const int inf=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
using namespace std;
int n,m,c[N],ans;
char s[N];
vector<int> v;
bool vis[N];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void dfs(int x)
{
	if(x>n)
	{
		int cnt=0,sum=0;
		rep1(i,1,n)
		{
			if(cnt>=c[v[i]]||s[i]=='0')
			{
				++cnt;
				continue;
			}
			else ++sum;
		}
		if(sum>=m) ans=(ans+1)%mod;
		return;
	}
	rep1(i,1,n)
	{
		if(vis[i]) continue;
		vis[i]=1;
		v.push_back(i);
		dfs(x+1);
		v.pop_back();
		vis[i]=0;
	}
	return;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	bool res=1;
	rep1(i,1,n) 
	{
		cin>>s[i];
		if(s[i]=='0') res=0;
	}
	rep1(i,1,n) c[i]=read();
	if(n<=10)
	{
		v.push_back(0);
		dfs(1);
		cout<<ans<<"\n";
		return 0;
	}
	else if(m==n)
	{
		int cnt=0;
		rep1(i,1,n) if(!c[i]) ++cnt;
		if(cnt||!res) puts("0");
		else
		{
			ans=1;
			rep1(i,1,n) ans=ans*i%mod;
			cout<<ans<<"\n";
		} 
	}
	return 0;
}
/*
3 3
111
1 1 2
*/
