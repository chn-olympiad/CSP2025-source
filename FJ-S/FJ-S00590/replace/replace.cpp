#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define N 200006
#define M 5000006
#define B 5006
#define MOD 1000000007
using namespace std;
char s[M],t[M];
char ch[B][B],tmp[M];
int n,q,len[N],hs1[N],hs2[N],pos[N];
int get_has(char *c,int l,int r)
{
	int has=0;
	for(int i=l;i<=r;i++)has=has*131+c[i],has%=MOD;
	return has;
}
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%s",s+1,t+1);
		int lt=strlen(s+1),l,r;
		for(l=1;s[l]==t[l];l++)ch[i][++len[i]]=s[l];
		ch[i][++len[i]]='#',pos[i]=len[i];
		for(r=lt;s[r]==t[r];r--)ch[i][++len[i]]=t[l];
		hs1[i]=get_has(s,l,r),hs2[i]=get_has(t,l,r);
	}
	while(q--)
	{
		int ans=0;
		scanf("%s%s",s+1,t+1);
		if(strlen(s+1)!=strlen(t+1)){printf("0\n");continue;}
		int lt=strlen(s+1),tmplen=0,l,r;
		for(l=1;s[l]==t[l];l++)tmp[++tmplen]=s[l];
		tmp[++tmplen]='#'; int p=tmplen;
		for(r=lt;s[r]==t[r];r--)tmp[++tmplen]=t[l];
		int h1=get_has(s,l,r),h2=get_has(t,l,r);
		for(int i=1;i<=n;i++)if(hs1[i]==h1&&hs2[i]==h2)
		{
			if(pos[i]>p)continue;
			if(p-pos[i]+len[i]>tmplen)continue;
			int flag=1;
			for(int j=1;j<=len[i];j++)flag&=ch[i][j]==tmp[p-pos[i]+j];
			ans+=flag;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
