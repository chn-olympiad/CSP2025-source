// Ñ¹Ëõ°üÃÜÂë: Ren5Jie4Di4Ling5%
// 15:21 Íê³É T1 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define set0(a) memset((a),0,sizeof((a)))
namespace IO
{
	void read(int &x)
	{
		x=0; char c=getchar();
		while(!isdigit(c)) c=getchar();
		while(isdigit(c)){ x=(x<<3)+(x<<1)+(c^48); c=getchar(); }
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
	const int N=100005;
	int _,n,a[N][3],b[N],c[N],ans,cnt[3];
	vector<int>v;
	void main()
	{
		read(_);
		while(_--)
		{
			ans=0;
			v.clear();
			set0(cnt);
			read(n);
			for(int i=1;i<=n;i++)
			{
				b[i]=0;
				for(int j=0;j<3;j++)
				{
					read(a[i][j]);
					if(a[i][j]>a[i][b[i]])
					{
						b[i]=j;
					}
				}
				c[i]=a[i][b[i]];
				cnt[b[i]]++;
				ans+=a[i][b[i]];
				for(int j=0;j<3;j++)
				{
					if(j^b[i])
					{
						c[i]=min(c[i],a[i][b[i]]-a[i][j]);
					}
				}
//				printf("i=%lld, b[i]=%lld, c[i]=%lld, ans=%lld\n",i,b[i],c[i],ans);
			}
			for(int j=0;j<3;j++)
			{
				if(cnt[j]>(n>>1))
				{
					for(int i=1;i<=n;i++)
					{
						if(b[i]==j)
						{
							v.pb(c[i]);
						}
					}
					sort(all(v));
					for(int i:v)
					{
						if(cnt[j]<=(n>>1))
						{
							break;
						}
						ans-=i;
						--cnt[j];
					}
					break;
				}
			}
			writeln(ans);
		}
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	W_C_B_H::main();
	return 0;
}
