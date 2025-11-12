#include<bits/stdc++.h>
using namespace std;
int n,q,l,r,cd,tot,bb,oto,f[5000005][30],head[5000005],js[200005],lw[200005],rw[200005],ww,ans;
struct pp
{
	int to,nxt;
}dl[400005];
long long zh1,zh2,zh3,zh4;
map<long long , map<long long, map<long long , map<long long ,long long> > > >bh;
int read()
{
	int x=0;bool f=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f=!(ch^45);
	for(;isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+(ch^48);
	return (f?-x:x);
}
const long long mod1=1e9+7,mod2=998244353,cs1=13331,cs2=31;
char ch[5000005],ch1[5000005];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ch+1);
		scanf("%s",ch1+1);
		cd=strlen(ch+1);
		l=0;
		r=cd+1;
		for(int j=1;j<=cd;j++)
		{
			if(ch[j]==ch1[j]) l=j;
			else break;
		}
		for(int j=cd;j>=1;j--)
		{
			if(ch[j]==ch1[j]) r=j;
			else break;
		}
		if(l+1>=r)
		{
			i--;
			n--;
			continue;
		}
		zh1=0;
		zh2=0;
		zh3=0;
		zh4=0;
		for(int j=l+1;j<r;j++)
		{
			zh1=(zh1*cs1%mod1+(ch[j]-'a'+1))%mod1;
			zh2=(zh2*cs2%mod2+(ch[j]-'a'+1))%mod2;
			zh3=(zh3*cs1%mod1+(ch1[j]-'a'+1))%mod1;
			zh4=(zh4*cs2%mod2+(ch1[j]-'a'+1))%mod2;
		}
		if(bh[zh1][zh2][zh3][zh4]==0)
		{
			bh[zh1][zh2][zh3][zh4]=++tot;
			lw[tot]=++oto;
			rw[tot]=++oto;
		}
		bb=bh[zh1][zh2][zh3][zh4];
		ww=lw[bb];
		for(int j=l;j>=1;j--)
		{
			if(f[ww][ch[j]-'a'+1]==0) f[ww][ch[j]-'a'+1]=++oto;
			ww=f[ww][ch[j]-'a'+1];
		}
		dl[i*2-1].to=i;
		dl[i*2-1].nxt=head[ww];
		head[ww]=i*2-1;
		ww=rw[bb];
		for(int j=r;j<=cd;j++)
		{
			if(f[ww][ch[j]-'a'+1]==0) f[ww][ch[j]-'a'+1]=++oto;
			ww=f[ww][ch[j]-'a'+1];
		}
		dl[i*2].to=i;
		dl[i*2].nxt=head[ww];
		head[ww]=i*2;
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%s",ch+1);
		scanf("%s",ch1+1);
		ans=0;
		cd=strlen(ch+1);
		l=0;
		r=cd+1;
		for(int j=1;j<=cd;j++)
		{
			if(ch[j]!=ch1[j]) break;
			else l=j;
		}
		for(int j=cd;j>=1;j--)
		{
			if(ch[j]!=ch1[j]) break;
			else r=j;
		}
		zh1=0;
		zh2=0;
		zh3=0;
		zh4=0;
		for(int j=l+1;j<r;j++)
		{
			zh1=(zh1*cs1%mod1+(ch[j]-'a'+1))%mod1;
			zh2=(zh2*cs2%mod2+(ch[j]-'a'+1))%mod2;
			zh3=(zh3*cs1%mod1+(ch1[j]-'a'+1))%mod1;
			zh4=(zh4*cs2%mod2+(ch1[j]-'a'+1))%mod2;
		}
		if(bh[zh1][zh2][zh3][zh4]==0)
		{
			printf("0\n");
			continue;
		}
		bb=bh[zh1][zh2][zh3][zh4];
		ww=lw[bb];
		for(int k=head[ww];k;k=dl[k].nxt) js[dl[k].to]=1;
		for(int j=l;j>=1;j--)
		{
			if(!f[ww][ch[j]-'a'+1]) break;
			ww=f[ww][ch[j]-'a'+1];
			for(int k=head[ww];k;k=dl[k].nxt) js[dl[k].to]=1;
		}
		ww=rw[bb];
		for(int k=head[ww];k;k=dl[k].nxt) if(js[dl[k].to]) ans++;
		for(int j=r;j<=cd;j++)
		{
			if(!f[ww][ch[j]-'a'+1]) break;
			ww=f[ww][ch[j]-'a'+1];
			for(int k=head[ww];k;k=dl[k].nxt) if(js[dl[k].to]) ans++;
		}
		ww=lw[bb];
		for(int k=head[ww];k;k=dl[k].nxt) js[dl[k].to]=0;
		for(int j=l;j>=1;j--)
		{
			if(!f[ww][ch[j]-'a'+1]) break;
			ww=f[ww][ch[j]-'a'+1];
			for(int k=head[ww];k;k=dl[k].nxt) js[dl[k].to]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}
