#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
constexpr int N=2e5,L=5e6;
constexpr long long R=13331,M=1e9+9;
struct str
{
	long long h[2];
	int len;
};
str s[L+5];
char t[2][L+5];
long long th[2][L+5],pw[L+5];
inline long long hs(long long h[],int r,int len)
{
	return ((h[r]-h[r-len]*pw[len])%M+M)%M;
}
int main()
{
	pw[0]=1;
	for(int i=1;i<=L;i++)
		pw[i]=pw[i-1]*R%M;
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",t[0]+1,t[1]+1);
		s[i].len=strlen(t[0]+1);
		for(int j=1;j<=s[i].len;j++)
		{
			s[i].h[0]=(s[i].h[0]*R+(t[0][j]-'a'+1))%M;
			s[i].h[1]=(s[i].h[1]*R+(t[1][j]-'a'+1))%M;
		}
//		printf("%lld %lld\n",s[i].h[0],s[i].h[1]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%s%s",t[0]+1,t[1]+1);
		int len0=strlen(t[0]+1),len1=strlen(t[1]+1);
		if(len0!=len1)
		{
			printf("0\n");
			continue;
		}
		int l=L,r=1;
		for(int j=1;j<=len0;j++)
		{
			if(t[0][j]!=t[1][j])
			{
				l=min(l,j);
				r=j;
			}
			th[0][j]=(th[0][j-1]*R+(t[0][j]-'a'+1))%M;
			th[1][j]=(th[1][j-1]*R+(t[1][j]-'a'+1))%M;
		}
//		printf("%lld %lld\n",th[0][len0],th[1][len0]);
		int cnt=0;
		for(int j=r;j<=len0;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(s[k].len<=j&&j-s[k].len<l&&
				s[k].h[0]==hs(th[0],j,s[k].len)&&s[k].h[1]==hs(th[1],j,s[k].len))
					cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
