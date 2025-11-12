#include<cstdio>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fe(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define un unsigned
const int N=2e5+5,L=5e6+5,M=1e7+3;
const un ll HS=37;
int n,Q,f[M];
un ll val[M][2],hs[L];
char a[L],b[L];
string c[N],d[N];
vector<un ll>sumc[N],sumd[N];
un ll suma[L],sumb[L];
int HA(un ll o,un ll p)
{
	int i=o*p%M;
	while(f[i]&&(val[i][0]!=o||val[i][1]!=p)) i=(i==M-1?0:i+1);
	return i;
}
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&Q);
	fo(I,1,n)
	{
		scanf("%s%s",a+1,b+1);
		int len=strlen(a+1);
		un ll o=0,p=0;
		fo(i,1,len) o=o*HS+(a[i]-'a'+1),p=p*HS+(b[i]-'a'+1);
		int x=HA(o,p);
		val[x][0]=o,val[x][1]=p,++f[x];
	}
	while(Q--)
	{
		scanf("%s%s",a+1,b+1);
		int len=strlen(a+1);
		if((int)strlen(b+1)!=len)
		{
			puts("0");
			continue;
		}
		int l=len+1,r=0;
		fo(i,1,len) if(a[i]!=b[i]) l=min(l,i),r=i;
		ll ans=0;
		fo(i,1,len)
		{
			un ll o=0,p=0;
			fo(j,i,len)
			{
				o=o*HS+(a[j]-'a'+1),p=p*HS+(b[j]-'a'+1);
				if(i<=l&&r<=j) ans+=f[HA(o,p)];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
