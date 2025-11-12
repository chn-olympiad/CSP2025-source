// 18:07 Íê³É T3 8pts 
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
	const int N=200005;
	int n,_,l[N],ans=0;
	string s[N][2],t[2];
	vector<int>nxt;
	void kmp(string x)
	{
		nxt.clear();
		nxt.pb(0);
		int _l=x.size();
		for(int i=1;i<_l;i++)
		{
			int j=nxt[i-1];
			while(j && x[j]!=x[i])
			{
				j=nxt[j-1];
			}
			if(x[j]==x[i])
			{
				j++;
			}
			nxt.pb(j);
		}
	}
	void main()
	{
		read(n), read(_);
		for(int i=1;i<=n;i++)
		{
			read(s[i][0]), read(s[i][1]);
			l[i]=s[i][0].size();
		}
		while(_--)
		{
			ans=0;
			read(t[0]), read(t[1]);
			if(t[0].size()!=t[1].size())
			{
				writeln(0);
				continue;
			}
			for(int i=1;i<=n;i++)
			{
//				printf("i=%lld\n",i);
				string x=s[i][0]+"#"+t[0];
				kmp(x);
				int k=x.size();
//				for(int j=0;j<k;j++)
//				{
//					printf("j=%lld, nxt[j]=%lld\n",j,nxt[j]);
//				}
				for(int j=l[i]<<1;j<k;j++)
				{
					if(nxt[j]==l[i])
					{
						if(t[0].substr(0,j-2*l[i]) + s[i][1] + (j<k-1 ? t[0].substr(j-l[i]) : "") == t[1])
						{
							ans++;
						}
					}
				}
			}
			writeln(ans);
		}
	}
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	W_C_B_H::main();
	return 0;
}
