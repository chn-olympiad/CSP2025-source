#include<bits/stdc++.h>
using namespace std;
#define pc putchar
#define we(x) (write(x),pc('\n'))
#define ws(x) (write(x),pc(' '))
#define rep(i,x,y) for(int i=x;i<=y;i++)
const int N=1e5,M=1e5,mod=998244353;
inline void read(int &x)
{
	x=0;
	register char ch;
	while((ch=getchar())<'0'||ch>'9');
	do
	{
		x=(x<<1)+(x<<3)+ch-'0';
	}while((ch=getchar())>='0'&&ch<='9');
}
inline void write(int x)
{
	if(x==0)
	{
		pc('0');
		return;
	}
	if(x>=10)write(x/10);
	pc(x%10+'0');
}
string s;
int n,m,c[N+5],vis[N+5],p[N+5],ans=0;
void dfs(int x)
{
	if(x>n)
	{
		int res=0,now=0;
		rep(i,1,n)
		{
			if(now>=c[p[i]])continue;
			if(s[i]=='1')++res,now=0;
			else ++now;
		}
		if(res>=m)++ans;
	}
	rep(i,1,n)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[x]=i;
		dfs(x+1);
		vis[i]=0;
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n),read(m);
	cin>>s;
	s=" "+s;
	rep(i,1,n)read(c[i]);
	dfs(1);
	we(ans);
}