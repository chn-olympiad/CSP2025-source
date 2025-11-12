// 17:34 完成 T4 8pts 
// 18:11 完成 T4 12pts 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define set0(a) memset((a),0,sizeof((a)))
#define setinf(a) memset((a),0x3f,sizeof((a)))
const int inf=0x3f3f3f3f, llinf=0x3f3f3f3f3f3f3f3f;
namespace IO
{
	void read(int &x)
	{
		x=0; char c=getchar();
		while(!isdigit(c)) c=getchar();
		while(isdigit(c)){ x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
	}
	void read(string &x)
	{
		x=""; char c=getchar();
		while(c==' ' || c=='\r' || c=='\n') c=getchar();
		while(c!=' ' && c!='\r' && c!='\n'){ x+=c; c=getchar(); }
	}
	void write(int x)
	{
		if(x>9) write(x/10);
		putchar(x%10^48);
	}
	void writeln(int x)
	{
		write(x); putchar('\n');
	}
}
namespace W_C_B_H	// Luogu UID: 527300
{
	using namespace IO;
	const int N=505, mod=998244353;
	int n,m,k=0,c[N],ans=0;
	string s;
	bool vis[N];
	void dfs(int p,int cnt)
	{
		if(p>n)
		{
			ans+=(cnt>=m);
			return;
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				if(p-cnt-1<c[i] && s[p]=='1')
				{
					dfs(p+1,cnt+1);
				}
				else
				{
					dfs(p+1,cnt);
				}
				vis[i]=0;
			}
		}
	}
	void main()
	{
		read(n), read(m), read(s);
		s=" "+s;
		for(int i=1;i<=n;i++)
		{
			read(c[i]);
			if(s[i]=='1')
			{
				k++;
			}
		}
		if(k<m)
		{
			putchar('0');
			return;
		}
		if(n==m)
		{
			for(int i=1;i<=n;i++)
			{
				if(!c[i])
				{
					putchar('0');
					return;
				}
				ans=ans*i%mod;
			}
			write(ans);
			return;
		}
		dfs(1,0);
		write(ans);
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	W_C_B_H::main();
	return 0;
}
