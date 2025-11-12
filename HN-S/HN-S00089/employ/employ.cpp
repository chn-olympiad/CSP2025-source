#include <bits/stdc++.h>
using namespace std;
#ifdef __linux__
#define gc getchar_unlocked
#define pc putchar_unlocked
#else
#define gc _getchar_nolock
#define pc _putchar_nolock
#endif
#define _ read<int>()
#define int long long
#define rint register int
#define R register
template<class T>inline T read()
{
	T r=0,f=1;R char c=gc();
	while(!isdigit(c))
	{
		if(c=='-') f=-1;
		c=gc();
	}
	while(isdigit(c)) r=(r<<1)+(r<<3)+(c^48),c=gc();
	return f*r;
}
inline void out(rint x)
{
	if(x<0) pc('-'),x=-x;
	if(x<10) pc(x+'0');
	else out(x/10),pc(x%10+'0');
}
const int N=510,mod=998244353;
int c[N],n,m,a[N],ans;
bitset<N>vis,s;
inline void dfs(rint d)
{
	if(d>n)
	{
		rint tao=0,nt=0;
		for(rint i=1;i<=n;i++)
		{
			if(tao<a[i]&&s[i]) nt++;
			else tao++;
			if(nt>=m) break;
		}
		if(nt>=m) ans++;
		return;
	}
	for(rint i=1;i<=n;i++)
	{
		if(!vis[i])
		{ 
			a[d]=c[i];
			vis[i]=1; 
			dfs(d+1);
			vis[i]=0;
		}	
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=_,m=_;
	cin>>s;
	for(rint i=n;i>=1;i--) s[i]=s[i-1];
	rint co=0;
	for(rint i=1;i<=n;i++) c[i]=_,co+=(!c[i]?1:0);
	bool f=1;
	for(rint i=1;i<=n;i++) f&=(s[i]-'0');
	if(n-co<m)
	{
		puts("0");return 0;
	}
	dfs(1);
	out(ans);
	return 0;
}

