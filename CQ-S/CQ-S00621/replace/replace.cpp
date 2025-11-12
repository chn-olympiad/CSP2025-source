/*
出发！前进！ 
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
/*
cirno /se /se
furina /se /se
yanami /se /se
yamada /se /se
sayaka /se /se
konata /se /se
蓝仙未未 /se /se 
*/
namespace TYX_YNXK{
	#define il inline
	#define vd void
	#define bl bool
	#define ll long long
	#define ull unsigned ll
	#define db double
	#define ldb long db
	#define pii pair<int,int>
	#define fi first
	#define se second
	#define MP make_pair
	#define pb push_back
	#define N 200005
	#define M 5000005
	#define INF
	#define DEBUG cerr<<"\tfurina begin:\n"
	#define END cerr<<"\tyanami end.\n"
	#define c ch=getchar()
	il unsigned read(){
		unsigned x=0;char c;
		for(;ch<48||ch>57;c);
		for(;ch>47&&ch<58;c)x=(x<<3)+(x<<1)+(ch^48);
		return x;
	}
	#undef c
	const ull base=27044333;//我要向全世界推广这个素数：27044333=54088666/2 
	int n,q,ans[N],t[2][M][26],Node[2],dfn[M],sz[M],dcnt;char ch1[M],ch2[M];
	struct BIT{
		int t[M];
		il vd add(int x,int v){for(;x<=dcnt;x+=x&-x)t[x]+=v;}
		il int sum(int x){int r=0;for(;x;x&=x-1)r+=t[x];return r;}
	}T;
	struct XP{
		string pre,suf;int id;
		pair<ull,ull>val;
	};vector<XP>CCD;pair<ull,ull>b[N];int p;
	vector<XP>A[N];vector<XP>B[N];
	il int insert(int ty,string&ch){
		int len=ch.size(),u=0;
		for(int i=0;i<len;i++){
			int c=ch[i]-'a';
			if(!t[ty][u][c])t[ty][u][c]=++Node[ty];
			u=t[ty][u][c];
		}return u;
	}
	il int query(int ty,string&ch){
		int len=ch.size(),u=0;
		for(int i=0;i<len;i++){
			int c=ch[i]-'a';
			if(!t[ty][u][c])return u;
			u=t[ty][u][c];
		}return u;
	}
	vector<int>U[M];vector<pii >Q[M];
	vd dfs1(int u){
		dfn[u]=++dcnt,sz[u]=1;
		for(int c=0;c<26;c++)if(t[1][u][c])dfs1(t[1][u][c]),sz[u]+=sz[t[1][u][c]];
	}
	vd dfs0(int u){
		for(int&v:U[u])T.add(dfn[v],1),T.add(dfn[v]+sz[v],-1);
		for(pii&pos:Q[u])ans[pos.se]+=T.sum(dfn[pos.fi]);
		for(int c=0;c<26;c++)if(t[0][u][c])dfs0(t[0][u][c]);
		for(int&v:U[u])T.add(dfn[v],-1),T.add(dfn[v]+sz[v],1);
	}
	signed main(){
		n=read(),q=read();
		for(int i=1;i<=n;i++){
			scanf("%s%s",ch1+1,ch2+1);int len=strlen(ch1+1);
			int l=-1,r=n+1;
			for(int j=1;j<=len;j++)if(ch1[j]^ch2[j]){l=j;break;}
			for(int j=len;j>=1;j--)if(ch1[j]^ch2[j]){r=j;break;}
			if(l==-1)continue;
			ull now1=0,now2=0;string pre,suf;
			for(int j=l;j<=r;j++)now1=now1*base+ch1[j];
			for(int j=l;j<=r;j++)now2=now2*base+ch2[j];
			for(int j=l-1;j>=1;j--)pre+=ch1[j];for(int j=r+1;j<=len;j++)suf+=ch1[j];
			CCD.pb((XP){pre,suf,0,MP(now1,now2)}),b[++p]=MP(now1,now2);
		}sort(b+1,b+1+p),p=unique(b+1,b+1+p)-b-1;
		for(XP&pos:CCD)A[lower_bound(b+1,b+1+p,pos.val)-b].pb(pos);
		for(int i=1;i<=q;i++){
			scanf("%s%s",ch1+1,ch2+1);int len=strlen(ch1+1);
			int l=-1,r=n+1;
			for(int j=1;j<=len;j++)if(ch1[j]^ch2[j]){l=j;break;}
			for(int j=len;j>=1;j--)if(ch1[j]^ch2[j]){r=j;break;}
			ull now1=0,now2=0;string pre,suf;
			for(int j=l;j<=r;j++)now1=now1*base+ch1[j];
			for(int j=l;j<=r;j++)now2=now2*base+ch2[j];
			for(int j=l-1;j>=1;j--)pre+=ch1[j];for(int j=r+1;j<=len;j++)suf+=ch1[j];
			int pos=lower_bound(b+1,b+1+p,MP(now1,now2))-b;
			if(b[pos]==MP(now1,now2))B[pos].pb((XP){pre,suf,i,MP(now1,now2)});
		}
		for(int i=1;i<=p;i++)if(!B[i].empty()){
			for(XP&pos:A[i]){
				int x=insert(0,pos.pre),y=insert(1,pos.suf);
				U[x].pb(y);
			}
			dfs1(0);
			for(XP&pos:B[i]){
				int x=query(0,pos.pre),y=query(1,pos.suf);
				Q[x].pb(MP(y,pos.id));
			}
			dfs0(0);
			for(int ty=0;ty<2;ty++)for(int j=0;j<=Node[ty];j++)for(int c=0;c<26;c++)t[ty][j][c]=0;
			for(int j=0;j<=Node[0];j++)U[j].clear(),Q[j].clear();
			Node[0]=Node[1]=dcnt=0;
		}
		for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
		return 0;
	}
}signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	TYX_YNXK::main();
//	while(1);
	return 0;
}/*
y^2=ax^3+bx+c 椭圆曲线保佑
TL: 1.0s
ML: 2GB
*/
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
/*
起码 200 了。
但是看到字符串我整个人都不好了。 
wee 这个过程原来不是递归的。
就是问你两个不同的字符串有多少个满足 x+y+z x+y'+z。
合法替换数量 2e5，总长度 5e6。必须 O(n)。 
好像不太能 kmp。那是 O(n+m) 的，这边绝对爆炸。
AC 自动机行不？虽然 S 组不太可能考这东西。
哈希大概是。
至少会了根号做法。
可是问题在于我们不可避免的要跑匹配。
多串不是 AC 自动机就只能是 Trie 了。

注意到一件事：找到两个串中不同的点，考虑极小不同子段，这个子段必须被替换的 y 完全包含。
且这个子段的替换内容被钦定了。
其余的就是在这个子段拼前缀、后缀。
这个看着就很可做。
类似地，对每个替换串也预处理极小不同子段。
不难注意到可以匹配上当且仅当极小不同子段相同，且前后缀匹配。
wc 你不觉得这玩意很 nb 吗？
接下来唯一的问题就是这个前后缀相互匹配了。单次询问是简单的，枚举每一组 check 即可。
考虑我们的问题：对于某一个极小不同子段，给定前缀集合和后缀集合，问有多少替换串满足前后缀分别隶属。
前后缀同时枚举复杂度就错了，只能直接统计力。
不妨枚举前缀，然后求两集合的交？这个除遍历以外没有别的做法，别想了。

有点急，冷静一下。现在才 1h，正解都快出来了，别急。
把问题抽象出来：给你一个前缀和后缀，你有一个字符串对集合，问你有多少对能前缀的前缀，后缀的后缀。
对于这个字符串对集合，我们可以给前缀建 Trie，后缀也一样。
问题变成了双树祖先链交集大小。
考虑一对双树上的匹配点，问题相当于说给同时双树属于子树的加。
这是二维数点问题。然后我们做到了 log 的复杂度。

2e6 是可以过了，5e6 特意卡的话比较悬。我们希望 log 只和 2e5 有关。
一个典型思路是在第一棵树上 dfs，同时对第二棵树做子树加，查询的时候再查。
我真优化不了了。
不对，q<=2e5，查询也可以 log。
那还说啥嘞。

hash 使用次数不多，这边建议双 hash。
woc 感觉被卡常的一批啊。
不过树状数组应该还好捏。 

选手与出题人应该是互相信任的状态。
选手不应该去猜测出题人会卡自然溢出，这对选手和出题人都不好。
为了空出时间写 T4，我们还是写自然溢出吧。
出题人祝您母亲长命百岁，福如东海，寿比南山。当然是在不卡 hash 的前提下。 
*/
