#include<bits/stdc++.h>
#define ll int 
#define ygkg putchar(' ')
#define endl putchar('\n')
//const ll inf=1e16;
const ll mod=998244353;
namespace io
{
	template<typename L>
	void in(L &x)
	{
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f=ch=='-',ch=getchar();
		do{x=(x<<3)+(x<<1)+(ch^48);}while(isdigit(ch=getchar()));
		if(f) x=-x;
	}
	template<typename L>
	void _out(L x){if(x) _out(x/10),putchar((x%10)^48);}
	template<typename L>
	void out(L x){_out(x>0?x:(x?(putchar('-'),-x):(putchar('0'),0))),endl;}
}
using namespace io;
using namespace std;
ll que[7500015],lf,rt;
struct ACzdj
{
	ll nx[7500015][27],fail[7500015],cnt[7500015],sum[7500015],siz=0;
	void add(char s[])
	{
		ll len=strlen(s);
//		cout<<s<<" "<<len<<"|\n";
		ll u=0;
		for(ll i=0;i<len;++i)
		{
			ll w=s[i]-'a';
			if(!nx[u][w])
			{
				nx[u][w]=++siz;
				u=siz;
			}
			else u=nx[u][w];
		}
		++cnt[u];
	}
	void build()
	{
		lf=1,rt=0;
		for(ll i=0;i<27;++i)
			if(nx[0][i]) que[++rt]=nx[0][i];
		while(lf<=rt)
		{
			ll u=que[lf++];
			for(ll i=0;i<27;++i)
				if(nx[u][i]) fail[nx[u][i]]=nx[fail[u]][i],que[++rt]=nx[u][i];
				else sum[u]=sum[fail[u]]+cnt[u],nx[u][i]=nx[fail[u]][i];
		}
	}
	ll query(char s[])
	{
		ll len=strlen(s);
//		cout<<len<<",\n";
//		cout<<s<<" "<<len<<"||\n";
		ll u=0;
		ll ans=0;
		for(ll i=0;i<len;++i)
		{
			ll w=s[i]-'a';
			u=nx[u][w];
//			cout<<"->"<<u;
			ans+=sum[u];
//			cout<<i<<" "<<len<<"\n";
		}
		return ans;
	}
}f;
ll n,q;
char sA[2500015],sB[2500015],s[7500015];
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
//	cout<<char('z'+1);
	in(n),in(q);
	for(ll i=1;i<=n;++i)
	{
		ll tem=0;
		char ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		do{sA[tem++]=ch,ch=getchar();}while(ch>='a'&&ch<='z');
		sA[tem]=0;
		tem=0;
		ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		do{sB[tem++]=ch,ch=getchar();}while(ch>='a'&&ch<='z');
		sB[tem]=0;
//		cout<<tem<<"\n";
		ll len=strlen(sA);
		for(ll id=0;id<len;++id)
			s[id*3]=sA[id],s[id*3+1]=sB[id],s[id*3+2]='z'+1;
		s[len*3]=0;
		f.add(s);
	}
	f.build();
	for(ll i=1;i<=q;++i)
	{
		ll tem=0;
		char ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		do{sA[tem++]=ch,ch=getchar();}while(ch>='a'&&ch<='z');
		sA[tem]=0;
		tem=0;
		ch=getchar();
		while(ch<'a'||ch>'z') ch=getchar();
		do{sB[tem++]=ch,ch=getchar();}while(ch>='a'&&ch<='z');
		sB[tem]=0;
		if(strlen(sA)!=strlen(sB))
		{
			out(0);
			continue;
		}
//		cout<<tem<<"|\n";
		ll len=strlen(sA);
		for(ll id=0;id<len;++id)
			s[id*3]=sA[id],s[id*3+1]=sB[id],s[id*3+2]='z'+1;
		s[len*3]=0;
		ll ans=0;
		ans+=f.query(s);
		ll l=0,r=len;
		for(ll i=len-1;i>=0;--i)
			if(sA[i]!=sB[i]){r=i;break;}
		for(ll id=l;id<r;++id)
			s[(id-l)*3]=sA[id],s[(id-l)*3+1]=sB[id],s[(id-l)*3+2]='z'+1;
		s[(r-l)*3]=0;
		ans-=f.query(s);
		l=0,r=len;
		for(ll i=0;i<len;++i)
			if(sA[i]!=sB[i]){l=i+1;break;}
		for(ll id=l;id<r;++id)
			s[(id-l)*3]=sA[id],s[(id-l)*3+1]=sB[id],s[(id-l)*3+2]='z'+1;
		s[(r-l)*3]=0;
		ans-=f.query(s);
		l=0,r=len;
		for(ll i=len-1;i>=0;--i)
			if(sA[i]!=sB[i]){r=i;break;}
		for(ll i=0;i<len;++i)
			if(sA[i]!=sB[i]){l=i+1;break;}
		for(ll id=l;id<r;++id)
			s[(id-l)*3]=sA[id],s[(id-l)*3+1]=sB[id],s[(id-l)*3+2]='z'+1;
		s[(r-l)*3]=0;
		ans+=f.query(s);
		out(ans);
	}
	return 0;
}
