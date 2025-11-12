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
const int N=2*1e5+100,P=11451419;
int n,q;
std::string s[N][2],t[N][2];
std::mt19937 rnd(time(0));
namespace solve1{
	int p=0,pw[N],h1[N],h2[N];
	std::map<pii,int> mp;
	int gha1(int l,int r)
	{
		int ha=h1[r]-h1[l-1]*pw[r-l+1]%P;
		if(ha<0) ha+=P;if(ha>=P) ha-=P;
		return ha;
	}
	int gha2(int l,int r)
	{
		int ha=h2[r]-h2[l-1]*pw[r-l+1]%P;
		if(ha<0) ha+=P;if(ha>=P) ha-=P;
		return ha;
	}
	void run()
	{
		p=rnd()+1e5;
		pw[0]=1;for(int i=1;i<=2000;i++) pw[i]=pw[i-1]*p%P;
		for(int i=1;i<=n;i++)
		{
			int ha1=0,ha2=0;
			for(auto j:s[i][0]) ha1=(ha1*p+j)%P;
			for(auto j:s[i][1]) ha2=(ha2*p+j)%P;
			mp[{ha1,ha2}]++;
		}
		for(int i=1;i<=q;i++)
		{
			if(t[i][0].size()!=t[i][1].size()){print(0);continue;}
			int len=t[i][0].size();
			for(int j=1;j<=len;j++) h1[j]=(h1[j-1]*p+t[i][0][j-1])%P;
			for(int j=1;j<=len;j++) h2[j]=(h2[j-1]*p+t[i][1][j-1])%P;
			int ans=0;
			for(int l=1;l<=len;l++)
			{
				if(h1[l-1]!=h2[l-1]) break;
				for(int r=len;r>=l;r--)
				{
					if(gha1(r+1,len)!=gha2(r+1,len)) break;
					int ha1=gha1(l,r),ha2=gha2(l,r);
					if(mp.count({ha1,ha2})) ans+=mp[{ha1,ha2}];
				}
			}
			print(ans);
		}
	}
}
namespace solve2{
	void run()
	{
		if(t[1][0].size()!=t[1][1].size()) return print(0);
		int pos1=0,pos2=0,m=t[1][0].size();
		for(int i=1;i<=m;i++)
		{
			if(t[1][0][i-1]=='b') pos1=i;
			if(t[1][1][i-1]=='b') pos2=i;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			int tpos1=0,tpos2=0,len=s[i][0].size();
			for(int j=1;j<=len;j++)
			{
				if(s[i][0][j-1]=='b') tpos1=j;
				if(s[i][1][j-1]=='b') tpos2=j;
			}
			if(tpos1-tpos2!=pos1-pos2) continue;
			if(len-tpos1>m-pos1) continue;
			if(tpos1-1>pos1-1) continue;
			ans++;
		}
		print(ans);
	}
}
signed main()
{
//	system("fc replace.out replace.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	int L1=0,L2=0;
	for(int i=1;i<=n;i++) std::cin>>s[i][0]>>s[i][1],L1+=s[i][0].size()+s[i][1].size();
	for(int i=1;i<=q;i++) std::cin>>t[i][0]>>t[i][1],L2+=t[i][0].size()+t[i][1].size();
	int flgB=1;
	for(int i=1;i<=n&&flgB;i++)
	{
		char ext='b';
		for(auto c:s[i][0])
		{
			if(c!='a'&&c!=ext){flgB=0;break;}
			if(c=='b') ext='0';
		}
		ext='b';
		for(auto c:s[i][1])
		{
			if(c!='a'&&c!=ext){flgB=0;break;}
			if(c=='b') ext='0';
		}
	}
	for(int i=1;i<=q&&flgB;i++)
	{
		char ext='b';
		for(auto c:t[i][0])
		{
			if(c!='a'&&c!=ext){flgB=0;break;}
			if(c=='b') ext='0';
		}
		ext='b';
		for(auto c:t[i][1])
		{
			if(c!='a'&&c!=ext){flgB=0;break;}
			if(c=='b') ext='0';
		}
	}
	if(L1<=2000&&L2<=2000) solve1::run();
	else if(flgB&&q==1) solve2::run();
	
	return 0;
}
