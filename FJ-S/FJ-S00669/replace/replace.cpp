#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
void read(int &n){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
void read(ll &n){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
const int N=2e5+5,M=5e6+N,mod=1e9+3,mod2=53317;
int n,m;
map<ll,int>ma[mod2];int cnt;
char c1[N],c2[N];int tot2;
int ql[N],qr[N],qpos[N],qro[N];
ll has[N];
char ask[M];int task;
int ans[N];
ll qpow[N];
char tl[M],tr[M];
int tot[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(m);
	qpow[0]=1;
	for(int i=1;i<=200000;i++)qpow[i]=qpow[i-1]*27%mod;
	for(int i=1;i<=n;i++){
		scanf("%s",c1+1);tot2=strlen(c1+1);
		scanf("%s",c2+1);
		tot[i]=tot[i-1];
		for(int j=1;j<=tot2;j++){
			tot[i]++;tl[tot[i]]=c1[j];tr[tot[i]]=c2[j];
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%s",c1+1);tot2=strlen(c1+1);
		scanf("%s",c2+1);
		int l=1,r=tot2;
		while(c1[l]==c2[l])l++;
		while(c1[r]==c2[r])r--;
		ll s=0,t=0;
		for(int j=l;j<=r;j++){
			s=s*27+c1[j]-'a';s%=mod2;
			t=t*27+c2[j]-'a';t%=mod;
//			cout<<s<<endl;
		}
//		cout<<s<<' '<<t<<endl;
		int ro=0;
		if(ma[s][t]==0){
			ma[s][t]=++cnt;
		}
		ro=ma[s][t];
		c1[l]='{';
		for(int j=l+1;j<=n-(r-l+1)+1;j++){
			c1[j]=c1[j+(r-l)];
		}
		tot2=tot2-(r-l);
		ql[i]=task+1;
		for(int j=1;j<=tot2;j++){
			ask[++task]=c1[j];qr[i]=task;
			if(ask[task]=='{')qpos[i]=j,qro[i]=ro; 
			has[task]=has[task-1]*27+ask[task]-'a';
			has[task]%=mod;
		}
	}
	for(int i=1;i<=n;i++){
		tot2=0;
		for(int j=tot[i-1]+1;j<=tot[i];j++){
			c1[++tot2]=tl[j];c2[tot2]=tr[j];
		}
		int l=1,r=tot2;
		while(c1[l]==c2[l])l++;
		while(c1[r]==c2[r])r--;
//		cout<<l<<' '<<r<<endl;
		ll s=0,t=0;
		for(int j=l;j<=r;j++){
			s=s*27+c1[j]-'a';s%=mod2;
			t=t*27+c2[j]-'a';t%=mod;
		}
		int ro=0;
		if(ma[s][t]==0){
			ma[s][t]=++cnt;
		}
		ro=ma[s][t];
		c1[l]='{';
		for(int j=l+1;j<=n-(r-l+1)+1;j++){
			c1[j]=c1[j+(r-l)];
		}
		tot2=tot2-(r-l);
		ll fhas=0;
		for(int i=1;i<=tot2;i++){
			fhas=fhas*27+c1[i]-'a';fhas%=mod;
		}
		for(int j=1;j<=m;j++){
			if(qro[j]!=ro)continue;
			if(qpos[j]-ql[j]>=l-1&&qr[j]-qpos[j]>=tot2-l){
//				cout<<ro<<' '<<qro[j]<<endl;
				ll dhas=has[qpos[j]+tot2-l]-has[qpos[j]-(l-1)-1]*qpow[tot2]%mod;
				dhas+=mod;dhas%=mod;
//				cout<<dhas<<' '<<fhas<<' '<<tot2<<endl;
//				cout<<qpos[j]+tot2-l<<' '<<qpos[j]-(l-1)-1<<endl;
				if(dhas==fhas)ans[j]++;
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<'\n';
	return 0;
}
//ac自动机+重链剖分nlog^2，但是来不及写了/fn 
//666输入看反了 
//666样例堪比fjoi 

//自动机+树剖
//但是只写了一部分 

/*#include<bits/stdc++.h>
#define ll long long
#define il inline
using namespace std;
void read(int &n){
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}
void read(ll &n){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';c=getchar();
	}n=x*f;
}

const int N=2e5+5,M=5e6+N,mod=1e9+3,mod2=53317;

struct segment_tree{//区间和 
	int siz[M<<2],tree[M<<2],tag[M<<2];
	void push_down(int x){
		if(tag[x]!=-1){
			tag[x<<1]=tag[x];tag[x<<1|1]=tag[x];
			tree[x<<1]=tag[x]*siz[x<<1];tree[x<<1|1]=tag[x]*siz[x<<1|1];
			tag[x]=-1;
		}
	}
	il void push_up(int x){
		tree[x]=tree[x<<1]+tree[x<<1|1];
		siz[x]=siz[x<<1]+siz[x<<1|1];
	}
	void update2(int x,int l,int r,int q){
		if(l==r){
			siz[x]=1;return;
		}
		int mid=(l+r)/2;
		if(q<=mid)update2(x<<1,l,mid,q);
		else update2(x<<1|1,mid+1,r,q);
		push_up(x);
	}
	void update(int x,int l,int r,int ql,int qr,int w){
		if(ql<=l&&qr>=r){
			tag[x]=w;tree[x]=tag[x]*siz[x];return;
		}
		push_down(x);int mid=(l+r)/2;
		if(ql<=mid)update(x<<1,l,mid,ql,qr,w);
		if(qr>mid)update(x<<1|1,mid+1,r,ql,qr,w);
		push_up(x);
	} 
}T;
int n,m;
map<ll,int>ma[mod2];int cnt;
struct node{
	int ans,ch[27],fail;
	int dfn;
}z[M];
char c1[N],c2[N];int tot2;
int root[N],tot;
void add(int x){
	if(root[x]==0)root[x]=++tot;
	x=root[x];
	for(int i=1;i<=tot2;i++){
		if(z[x].ch[c1[i]-'a']==0){
			z[x].ch[c1[i]-'a']=++tot;
		}
		x=z[x].ch[c1[i]-'a'];
	}
	z[x].ans++;
}
vector<int>g[M];
void dfs(int x){
	if(z[x].fail!=x){
		g[z[x].fail].push_back(x);
	}
	for(int i=0;i<=26;i++){
		if(z[x].ch[i]){
			z[z[x].ch[i]].fail=z[z[x].fail].ch[i];
			if(z[x].ch[i]!=x)dfs(z[x].ch[i]);
		}else{
			z[x].ch[i]=z[z[x].fail].ch[i];
		}
	}
}
int siz[M],son[M];
void dfs2(int x){
	siz[x]=1;
	for(int i:g[x]){
		dfs2(i);
		if(siz[i]>siz[son[x]])son[x]=i;
		siz[x]+=siz[i]; 
	}
}
int tp[M],tim;
void dfs3(int x,int top){
	z[x].dfn=++tim;
	tp[x]=top;
	if(son[x]){
		dfs3(son[x],top);
	}
	for(int i:g[x]){
		if(i==son[x])continue;
		dfs3(i,i);
	}
}
void dfs4(int x){
	if(z[x].ans){
		T.update2(1,1,tim,z[x].dfn);
	}
	for(int i:g[x]){
		dfs4(i);
	}
}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;i++){
		scanf("%s",c1+1);tot2=strlen(c1+1);
		scanf("%s",c2+1);
		int l=1,r=tot2;
		while(c1[l]==c2[l])l++;
		while(c1[r]==c2[r])r--;
		ll s=0,t=0;
		for(int j=l;j<=r;j++){
			s=s*28+c1[j]-'a';s%=mod2;
			t=t*28+c2[j]-'a';t%=mod;
		}
		int ro=0;
		if(ma[s][t]==0){
			ma[s][t]=++cnt;
		}
		cout<<ma[s][t]<<endl;
		ro=ma[s][t];
		c1[l]='{';
		for(int j=l+1;j<=n-(r-l+1)+1;j++){
			c1[j]=c1[j+(r-l)];
		}
		tot2=tot2-(r-l);add(ro);
	}
	for(int i=1;i<=cnt;i++){
		int x=root[i];
		for(int i=0;i<=26;i++)if(z[x].ch[i]==0)z[x].ch[i]=x;z[x].fail=x;
		dfs(root[i]);
		dfs2(root[i]);
		dfs3(x,x);
		dfs4(x);
	}
	for(int i=1;i<=m;i++){
		T.update(1,1,tim,1,tim,0);
		scanf("%s",c1+1);tot2=strlen(c1+1);
		scanf("%s",c2+1);
		int l=1,r=tot2;
		while(c1[l]==c2[l])l++;
		while(c1[r]==c2[r])r--;
		ll s=0,t=0;
		for(int j=l;j<=r;j++){
			s=s*28+c1[j]-'a';s%=mod2;
			t=t*28+c2[j]-'a';t%=mod;
		}
		int ro=0;
		if(ma[s][t]==0){
			ma[s][t]=++cnt;
		}
		cout<<ma[s][t]<<endl;
		ro=ma[s][t];
		c1[l]='{';
		for(int j=l+1;j<=n-(r-l+1)+1;j++){
			c1[j]=c1[j+(r-l)];
		}
		tot2=tot2-(r-l);
		int x=ro;
		for(int i=1;i<=tot2;i++){
			x=z[x].ch[c1[i]-'a'];
			int j=x;
			while(z[x].fail!=x){
				int top=tp[x];
				T.update(1,1,tim,z[top].dfn,z[x].dfn,1);
				x=z[top].fail;
			}
		}
		cout<<T.tree[1]<<'\n';
	}
	return 0;
}
*/
