#include<bits/stdc++.h>
#define ______ namespace
#define _______ std
using ______ _______;
int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
bool st;
const int mxn=2e5+5;
const int mxm=5e6+5;
int tr[mxm][26],tcnt;
const int mod=1e9+9;
using ull=unsigned long long;
const ull up=23333333333333;
const int up2=1145141;
map<ull,pair<int,int>> rt;
int dfl[mxm],dfr[mxm],dcnt;
int wl[mxn],wr[mxn];
int ins(int rt,char s[],int len)
{
	int i;
	for(i=0;i<len;i++)
	{
//		if(!(0<=s[i]-'a'&&s[i]-'a'<26))
//			cout<<len<<'#'<<s[i]<<endl;
//		assert(0<=s[i]-'a'&&s[i]-'a'<26);
		if(!tr[rt][s[i]-'a']) tr[rt][s[i]-'a']=++tcnt;
		rt=tr[rt][s[i]-'a'];
	}
	return rt;
}
char s1[mxm],s2[mxm];
char t1[mxm],t2[mxm];
int ans[mxn];
ull hs[mxn];
struct BIT
{
	#define lowbit(x) (x&-x)
	int t[mxm];
	void add(int x,int v)
	{
		for(;x<=tcnt;x+=lowbit(x))
			t[x]+=v;
	}
	int ask(int x)
	{
		int s=0;
		for(;x;x-=lowbit(x))
			s+=t[x];
		return s;
	}
}T;
void dfs(int d)
{
	dfl[d]=++dcnt;
	for(int i=0;i<26;i++)
		if(tr[d][i])
			dfs(tr[d][i]);
	dfr[d]=dcnt;
}
vector<int> qwq[mxm];
vector<pair<int,int>> que[mxm];
void dfs2(int d)
{
	for(auto x:qwq[d])
		T.add(dfl[x],1),T.add(dfr[x]+1,-1);
	for(auto x:que[d])
		ans[x.second]+=T.ask(dfl[x.first]);
	for(int i=0;i<26;i++)
		if(tr[d][i])
			dfs2(tr[d][i]);
	for(auto x:qwq[d])
		T.add(dfl[x],-1),T.add(dfr[x]+1,1);
}
bool ed;
int main()
{
//	cout<<(&st-&ed)/(1<<20);
//	system("fc replace.out replace4.ans");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read(),i,j;
	for(i=1;i<=n;i++)
	{
		scanf("%s%s",s1,s2);
//		cout<<i<<endl;
		int len=strlen(s1);
		int l,r;
		for(l=0;l<len&&s1[l]==s2[l];l++);
		if(l==len) continue;
		for(r=len-1;s1[r]==s2[r];r--);
		ull h=0;
		int h2=0;
		for(j=l;j<=r;j++)
			h=h*up+s1[j],h=h*up+s2[j],
			h2=(1ll*h2*up2+s1[j])%mod,h2=(1ll*h2*up2+s2[j])%mod;
		h+=h2;
		hs[i]=h;
		pair<int,int> rr;
		if(rt.count(h)) rr=rt[h];
		else rr=rt[h]=make_pair(tcnt+1,tcnt+2),tcnt+=2;
		reverse(s1,s1+l);
		wl[i]=ins(rr.first,s1,l);
		wr[i]=ins(rr.second,s1+r+1,len-r-1);
		qwq[wl[i]].push_back(wr[i]);
	}
	for(i=1;i<=tcnt;i++)
		if(!dfl[i])
			dfs(i);
	for(i=1;i<=q;i++)
	{
		scanf("%s%s",t1,t2);
		int len=strlen(t1);
		if(len!=strlen(t2)) continue;
		int l,r;
		for(l=0;t1[l]==t2[l];l++);
		for(r=len-1;t1[r]==t2[r];r--);
		ull h=0;
		int h2=0;
		for(j=l;j<=r;j++)
			h=h*up+t1[j],h=h*up+t2[j],
			h2=(1ll*h2*up2+t1[j])%mod,h2=(1ll*h2*up2+t2[j])%mod;
		h+=h2;
		if(!rt.count(h)) continue;
		pair<int,int> rr=rt[h];
		int w1=rr.first,w2=rr.second;
		for(j=l-1;~j;j--)
			if(tr[w1][t1[j]-'a'])
				w1=tr[w1][t1[j]-'a'];
			else break;
		for(j=r+1;j<len;j++)
			if(tr[w2][t1[j]-'a'])
				w2=tr[w2][t1[j]-'a'];
			else break;
		que[w1].push_back({w2,i});
//		for(j=1;j<=n;j++)
//			if(wl[j]&&dfl[wl[j]]<=dfl[w1]&&dfl[w1]<=dfr[wl[j]]&&dfl[wr[j]]<=dfl[w2]&&dfl[w2]<=dfr[wr[j]])
//				ans[i]++;
	}
	for(auto x:rt)
		dfs2(x.second.first),dfs2(x.second.second);
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}
