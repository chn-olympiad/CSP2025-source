//55min，有点慢了
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5,p1=131,p2=19491001,mod1=998244853,mod2=1e9+9,M=1e7+5;
bool stt;
int n,q,lenn[N],lenq[N],tot,rt[N][2],tot1,ed[N][2],sign,dfn[M],sz[M],anss[N],ss[N];
string s[N][2],t[N][2];
int ch[M][26];
map<array<int,4>,int>mp;
vector<array<int,4> >alladd;
vector<array<int,3> >allqry;
void dfs1(int x)
{
	sz[x]=1,sign++,dfn[x]=sign;
	for(int i=0;i<26;i++)if(ch[x][i])dfs1(ch[x][i]),sz[x]+=sz[ch[x][i]];
}
int cx[N*3],cy[N*3];
vector<pair<int,int> >que[N*3],oper[N*3];
struct BIT
{
	int t[N*3];
	int lowbit(int x){return (x&-x);}
	void add(int x,int v){for(int i=x;i<=cy[0];i+=lowbit(i))t[i]+=v;}
	int ask(int x){int res=0;for(int i=x;i>=1;i-=lowbit(i))res+=t[i];return res;}
}t1;
bool edd;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cerr<<((&stt)-(&edd))/1024.0/1024<<"\n";
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1],lenn[i]=s[i][0].length();
	for(int i=1;i<=q;i++)cin>>t[i][0]>>t[i][1],lenq[i]=t[i][0].length();
	for(int i=1;i<=n;i++)
	{
		int L=0,R=lenn[i]-1;
		while(L<lenn[i] && s[i][0][L]==s[i][1][L])L++;
		while(R>=0 && s[i][0][R]==s[i][1][R])R--;
		if(L==lenn[i])continue;
		int h1=0,h2=0,h3=0,h4=0;
		for(int j=L;j<=R;j++)
		{
			h1=(1ll*p1*h1+s[i][0][j])%mod1,h2=(1ll*p1*h2+s[i][1][j])%mod1;
			h3=(1ll*p2*h3+s[i][0][j])%mod2,h4=(1ll*p2*h4+s[i][1][j])%mod2;
		}
		if(!mp.count({h1,h2,h3,h4}))mp[{h1,h2,h3,h4}]=++tot;
		int pos=mp[{h1,h2,h3,h4}];
		ss[i]=pos;
		
		if(!rt[pos][0])rt[pos][0]=++tot1;
		int np=rt[pos][0];
		for(int j=L-1;j>=0;j--)
		{
			int k=s[i][0][j]-'a';
			if(!ch[np][k])ch[np][k]=++tot1;
			np=ch[np][k];
		}
		ed[i][0]=np;

		if(!rt[pos][1])rt[pos][1]=++tot1;
		np=rt[pos][1];
		for(int j=R+1;j<lenn[i];j++)
		{
			int k=s[i][0][j]-'a';
			if(!ch[np][k])ch[np][k]=++tot1;
			np=ch[np][k];
		}
		ed[i][1]=np;
	}
	for(int i=1;i<=tot;i++)dfs1(rt[i][0]),dfs1(rt[i][1]);
	for(int i=1;i<=n;i++)alladd.push_back({dfn[ed[i][0]],dfn[ed[i][1]],dfn[ed[i][0]]+sz[ed[i][0]]-1,dfn[ed[i][1]]+sz[ed[i][1]]-1});
	for(int i=1;i<=q;i++)
	{
		int L=0,R=lenq[i]-1;
		while(L<lenq[i] && t[i][0][L]==t[i][1][L])L++;
		while(R>=0 && t[i][0][R]==t[i][1][R])R--;
		int h1=0,h2=0,h3=0,h4=0;
		for(int j=L;j<=R;j++)
		{
			h1=(1ll*p1*h1+t[i][0][j])%mod1,h2=(1ll*p1*h2+t[i][1][j])%mod1;
			h3=(1ll*p2*h3+t[i][0][j])%mod2,h4=(1ll*p2*h4+t[i][1][j])%mod2;
		}
		if(!mp.count({h1,h2,h3,h4}))continue;
		int pos=mp[{h1,h2,h3,h4}];

		int np=rt[pos][0];
		for(int j=L-1;j>=0;j--)
		{
			int k=t[i][0][j]-'a';
			if(!ch[np][k])break;
			np=ch[np][k];
		}
		int ed0=np;

		np=rt[pos][1];
		for(int j=R+1;j<lenq[i];j++)
		{
			int k=t[i][0][j]-'a';
			if(!ch[np][k])break;
			np=ch[np][k];
		}
		int ed1=np;

		allqry.push_back({dfn[ed0],dfn[ed1],i});
	}
	for(auto i:alladd)cx[0]++,cx[cx[0]]=i[0],cx[0]++,cx[cx[0]]=i[2],cy[0]++,cy[cy[0]]=i[1],cy[0]++,cy[cy[0]]=i[3];
	for(auto i:allqry)cx[0]++,cx[cx[0]]=i[0],cy[0]++,cy[cy[0]]=i[1];
	sort(cx+1,cx+cx[0]+1),cx[0]=unique(cx+1,cx+cx[0]+1)-cx-1;
	sort(cy+1,cy+cy[0]+1),cy[0]=unique(cy+1,cy+cy[0]+1)-cy-1;
	for(auto &i:alladd)
	{
		i[0]=lower_bound(cx+1,cx+cx[0]+1,i[0])-cx,i[1]=lower_bound(cy+1,cy+cy[0]+1,i[1])-cy;
		i[2]=lower_bound(cx+1,cx+cx[0]+1,i[2])-cx,i[3]=lower_bound(cy+1,cy+cy[0]+1,i[3])-cy;
	}
	for(auto &i:allqry)i[0]=lower_bound(cx+1,cx+cx[0]+1,i[0])-cx,i[1]=lower_bound(cy+1,cy+cy[0]+1,i[1])-cy;
	for(auto i:alladd)
	{
		oper[i[0]].push_back({i[1],1}),oper[i[0]].push_back({i[3]+1,-1});
		oper[i[2]+1].push_back({i[1],-1}),oper[i[2]+1].push_back({i[3]+1,1});
	}
	for(auto i:allqry)que[i[0]].push_back({i[1],i[2]});
	for(int i=1;i<=cx[0];i++)
	{
		for(auto j:oper[i])t1.add(j.first,j.second);
		for(auto j:que[i])anss[j.second]=t1.ask(j.first);
	}
	for(int i=1;i<=q;i++)printf("%d\n",anss[i]);
	return 0;
}