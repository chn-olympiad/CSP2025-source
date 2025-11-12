#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
using namespace std;
namespace zzy{
	const int maxn=4e5+10;
	const int maxL=5e6+10;
	const int mod=1e9+7;
	int n,q,len,cnt,sum;
	string s1,s2;
	int ans[maxn];
	ull base1=740264624;
	int base2=99562947;
	inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
	int id1[maxn],id2[maxn];
	bool type[maxn];
	pair<ull,int>val[maxn];
	int p[maxn];
	inline bool cmp(int x,int y){return val[x]<val[y];}
	struct node{
		int son[26];
	}tree[maxL];
	int rt1,rt2,nodecnt;
	int insert1(int &v,int p){
		if(!v)v=++nodecnt;
		if(!p)return v;
		return insert1(tree[v].son[s1[p]-'a'],p-1);
	}
	int insert2(int &v,int p){
		if(!v)v=++nodecnt;
		if(p==len+1)return v;
		return insert2(tree[v].son[s1[p]-'a'],p+1); 
	}
	int in[maxL],out[maxL],dfncnt;
	void dfs(int u){
		in[u]=++dfncnt;
		for(int i=0;i<26;i++)if(tree[u].son[i])dfs(tree[u].son[i]);
		out[u]=dfncnt;
	}
	struct Operation{
		int p,type,id;
		bool operator < (const Operation &it)const{
			if(p!=it.p)return p<it.p;
			else return abs(type)>abs(it.type);
		}
	}opt[maxn<<1];
	int disc[maxn<<1],N;
	int ft[maxn<<1];
	inline int lowbit(int x){return -x&x;}
	inline void update(int l,int r,int k){
		for(int i=l;i<=N;i+=lowbit(i))ft[i]+=k;
		for(int i=r+1;i<=N;i+=lowbit(i))ft[i]-=k;
	}
	inline int ask(int x){
		int res=0;
		for(int i=x;i>=1;i-=lowbit(i))res+=ft[i];
		return res;
	}
	inline void solve(int l,int r){
		len=N=0;
		for(int i=l;i<=r;i++){
			int x=p[i];
			if(type[x]){
				opt[++len]={in[id1[x]],1,x};
				opt[++len]={out[id1[x]]+1,-1,x};
				disc[++N]=in[id2[x]],disc[++N]=out[id2[x]];
			}else{
				opt[++len]={in[id1[x]],0,x};
				disc[++N]=in[id2[x]];
			}
		}
		sort(disc+1,disc+N+1);N=unique(disc+1,disc+N+1)-disc-1;
		sort(opt+1,opt+len+1);
		for(int i=1;i<=len;i++){
			if(!opt[i].type){
				int x=lower_bound(disc+1,disc+N+1,in[id2[opt[i].id]])-disc;
				ans[opt[i].id]=ask(x);
			}else{
				int l=lower_bound(disc+1,disc+N+1,in[id2[opt[i].id]])-disc,r=lower_bound(disc+1,disc+N+1,out[id2[opt[i].id]])-disc;
				update(l,r,opt[i].type);
			}
		}
	}
	int main(){
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>s1>>s2;len=s1.size();
			s1=' '+s1,s2=' '+s2;
			int l=1,r=len;
			while(l<=len&&s1[l]==s2[l])l++;
			while(r>=1&&s1[r]==s2[r])r--;
			if(l==n+1)continue ;
			id1[i]=insert1(rt1,l-1);
			id2[i]=insert2(rt2,r+1);
			ull hs1=0;int hs2=0;
			for(int i=l;i<=r;i++)hs1=hs1*base1+s1[i],hs2=add(1ll*hs2*base2%mod,s1[i]);
			for(int i=l;i<=r;i++)hs1=hs1*base1+s2[i],hs2=add(1ll*hs2*base2%mod,s2[i]);
			val[i]={hs1,hs2};type[i]=1;
			p[++cnt]=i;
		}
		for(int i=1;i<=q;i++){
			cin>>s1>>s2;
			if(s1.size()!=s2.size())continue ;
			len=s1.size();
			sum+=len;
			s1=' '+s1,s2=' '+s2;
			int l=1,r=len;
			while(l<=len&&s1[l]==s2[l])l++;
			while(r>=1&&s1[r]==s2[r])r--;
			id1[n+i]=insert1(rt1,l-1);
			id2[n+i]=insert2(rt2,r+1);
			ull hs1=0;int hs2=0;
			for(int i=l;i<=r;i++)hs1=hs1*base1+s1[i],hs2=add(1ll*hs2*base2%mod,s1[i]);
			for(int i=l;i<=r;i++)hs1=hs1*base1+s2[i],hs2=add(1ll*hs2*base2%mod,s2[i]);
			val[n+i]={hs1,hs2};type[n+i]=0;
			p[++cnt]=n+i;
		}
		dfs(rt1),dfs(rt2);
		sort(p+1,p+cnt+1,cmp);
		for(int l=1,r;l<=cnt;l=r+1){
			r=l;
			while(r+1<=cnt&&val[p[r+1]]==val[p[l]])r++;
			solve(l,r);
		}
		for(int i=1;i<=q;i++)cout<<ans[n+i]<<'\n';

		return 0;
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	zzy::main();
	return 0;
}
/*
740MB
*/
/*
时代少年团我们喜欢你
*/
