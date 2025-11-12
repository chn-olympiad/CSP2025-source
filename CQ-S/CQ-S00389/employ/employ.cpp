#include<bits/stdc++.h>
using std::min;
using std::max;
using std::pair;
#define int long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define ppi pair<pii,int>
#define ppp pair<pii,pii>
#define edl putchar('\n')
#define lp first
#define rp second
#define lowbit ((x)&(-(x)))
const int inf=0x3f3f3f3f3f3f3f3f;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while('0'<=ch&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f*x;
}
void write(int x)
{
	if(x<0){x=-x;putchar('-');}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void print(int x,char ed='\n'){write(x);putchar(ed);}
const int N=5*1e2+100,P=998244353;
int n,m,c[N];
char s[N];
namespace solve1{
	int p[N];
	void run()
	{
		for(int i=1;i<=n;i++) p[i]=i;
		int ans=0;
		do{
			int dl=0;
			for(int i=1;i<=n;i++)
				if(s[i]=='0'||dl>=c[p[i]]) dl++;
			if(n-dl>=m) ans=(ans+1)%P;
		}while(std::next_permutation(p+1,p+n+1));
		print(ans);
	}
}
signed main()
{
//	system("fc employ.out employ3.ans");
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=read();
	int flgA=1;
	for(int i=1;i<=n;i++) flgA&=(s[i]=='1');
	solve1::run();
	
	return 0;
}
