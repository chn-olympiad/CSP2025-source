#include<bits/stdc++.h>
// #define int long long
#define mod 998244353ll
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,fl=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
const int maxn=200010;
const int maxm=5000010;
const int inf=1e9;

int n,q;
char s[maxm],t[maxm];
mt19937 rnd(time(0));
int bas,val[26];
map<pii,int> mp;int iidx;
vector<char> s1[maxn],s2[maxn];
vector<int> upd[maxn],que[maxn];
int ed[maxn<<1];
int ans[maxn];
int to[maxm][26],idx=1;
vector<int> add[maxm],ask[maxm];
int dfn[maxm],tim,siz[maxm];
void dfs(int u){
	dfn[u]=++tim;siz[u]=1;
	for(int i=0;i<26;i++)if(to[u][i]){
		int v=to[u][i];
		dfs(v);siz[u]+=siz[v];
	}
}
#define lb(x) (x&(-x))
struct bit{
int tree[maxm];
void upd(int x,int w){
	while(x<=tim)tree[x]+=w,x+=lb(x);
}
int que(int x){
	int res=0;
	while(x)res+=tree[x],x-=lb(x);
	return res;
}
}ds;
void dfs1(int u){
	for(int i:add[u]){
		// cout<<i<<" "<<dfn[ed[i]]<<" add\n";
		ds.upd(dfn[ed[i]],1),ds.upd(dfn[ed[i]]+siz[ed[i]],-1);
	}
	for(int i:ask[u]){
		// cout<<i<<" "<<dfn[ed[i]]<<" ask\n";
		ans[i]=ds.que(dfn[ed[i+n]]);
	}
	for(int i=0;i<26;i++)if(to[u][i]){
		int v=to[u][i];
		dfs1(v);
	}
	for(int i:add[u]){
		ds.upd(dfn[ed[i]],-1),ds.upd(dfn[ed[i]]+siz[ed[i]],1);
	}
}
void work(){
	bas=rnd()%mod;for(int i=0;i<26;i++)val[i]=rnd()%bas;
	n=read();q=read();
	for(int i=1;i<=n;i++){
		scanf("%s%s",s+1,t+1);int m=strlen(s+1);
		int l=1,r=m;
		while(l<=r&&s[l]==t[l])l++;
		while(l<=r&&s[r]==t[r])r--;
		for(int j=l-1;j;j--)s1[i].pb(s[j]);
		int h3=0;for(int i=l;i<=r;i++)h3=(1ll*h3*bas+val[s[i]-'a'])%mod;
		int h4=0;for(int i=l;i<=r;i++)h4=(1ll*h4*bas+val[t[i]-'a'])%mod;
		if(!mp[{h3,h4}])mp[{h3,h4}]=++iidx;
		upd[mp[{h3,h4}]].pb(i);
		int nd=1;
		for(int j=r+1;j<=m;j++){
			int c=s[j]-'a';
			if(!to[nd][c])to[nd][c]=++idx;
			nd=to[nd][c];
		}ed[i]=nd;
		// cout<<l<<" "<<r<<" "<<h3<<" "<<h4<<"\n";
	}
	dfs(1);
	for(int i=1;i<=q;i++){
		scanf("%s%s",s+1,t+1);int m=strlen(s+1);
		if(m!=strlen(t+1))ans[i]=0;
		else{
			int l=1,r=m;
			while(l<=r&&s[l]==t[l])l++;
			while(l<=r&&s[r]==t[r])r--;
			vector<int> v1,v2;
			for(int j=l-1;j;j--)s2[i].pb(s[j]);
			int h3=0;for(int i=l;i<=r;i++)h3=(1ll*h3*bas+val[s[i]-'a'])%mod;
			int h4=0;for(int i=l;i<=r;i++)h4=(1ll*h4*bas+val[t[i]-'a'])%mod;
			if(!mp[{h3,h4}])ans[i]=0;
			else{
				que[mp[{h3,h4}]].pb(i);
				int nd=1;
				for(int j=r+1;j<=m;j++){
					int c=s[j]-'a';
					if(!to[nd][c])break;
					nd=to[nd][c];
				}ed[i+n]=nd;
			}
		// cout<<l<<" "<<r<<" "<<h3<<" "<<h4<<"\n";
		}
	}
	while(idx){
		for(int c=0;c<26;c++)to[idx][c]=0;idx--;
	}idx=1;
	// cout<<iidx<<endl;
	for(int i=1;i<=iidx;i++)if(que[i].size()){
		for(int id:upd[i]){
			int nd=1;
			for(int j=0;j<s1[id].size();j++){
				int c=s1[id][j]-'a';
				if(!to[nd][c])to[nd][c]=++idx;
				nd=to[nd][c];
			}
			add[nd].pb(id);
			// cout<<id<<" "<<nd<<" add\n";
		}
		for(int id:que[i]){
			int nd=1;
			for(int j=0;j<s2[id].size();j++){
				int c=s2[id][j]-'a';
				if(!to[nd][c])break;
				nd=to[nd][c];
			}
			ask[nd].pb(id);
			// cout<<id<<" "<<nd<<" ask\n";
		}
		dfs1(1);
		while(idx){
			add[idx].clear(),ask[idx].clear();
			for(int c=0;c<26;c++)to[idx][c]=0;idx--;
		}idx=1;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
}

int T;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	T=1;
	while(T--)work();
}