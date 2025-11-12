#include<stdio.h>
#include<vector>
#include<string.h>
typedef long long ll;
const int N=2.5e6+5,M=2e5+5;
auto lowbit = [](int x) -> int {return x&~x+1;};
struct jie{int to,nxt;}e[2][N];
std::vector<int> v[N];
struct node1{
	int qid,to,len;
	node1(int _qid=0,int _to=0,int _len=0):qid(_qid),to(_to),len(_len){}
};
std::vector<node1> v1[N];
struct node2{
	int qid,to;
	node2(int _qid=0,int _to=0):qid(_qid),to(_to){}
};
std::vector<node2> v2[N]; 
int n,m,num1[M],num2[M],q[N],hh,tt,son[2][N][26],fail[2][N],cnt[2],len[2][N],id[2][N],size[2][N],dfn[2],head[2][N],cnt_edge[2],s[N],value[N],top,flag[N],c[N];
ll ans[N];
char s1[N<<1],s2[N<<1];
auto insert = [](int f,char *s) -> int {
	int p=0;
	for(int i=0,lst=0;s[i]!='\0';i++){
		int ch=s[i]-'a';
		if(son[f][p][ch]==0) son[f][p][ch]=++cnt[f];
		p=son[f][p][ch],len[f][p]=++lst;
	}
	return p;
};
auto add = [](int f,int x,int y) -> void {
	e[f][++cnt_edge[f]]={y,head[f][x]};
	head[f][x]=cnt_edge[f];
};
auto build = [](int f) -> void {
	hh=1,tt=0;
	for(int i=0;i<26;i++) if(son[f][0][i]) q[++tt]=son[f][0][i];
	while(hh<=tt){
		int u=q[hh++];
		for(int i=0;i<26;i++){
			if(son[f][u][i]) fail[f][son[f][u][i]]=son[f][fail[f][u]][i],q[++tt]=son[f][u][i];
			else son[f][u][i]=son[f][fail[f][u]][i];
		}
	}
	for(int i=1;i<=cnt[f];i++) add(f,fail[f][i],i);
};
auto dfs = [](auto &&self,int f,int u) -> void {
	id[f][u]=++dfn[f],size[f][u]=1;
	for(int i=head[f][u];i;i=e[f][i].nxt) self(self,f,e[f][i].to),size[f][u]+=size[f][e[f][i].to];
};
auto change = [](int x,int val) -> void {while(x<=dfn[1]) c[x]+=val,x+=lowbit(x);};
auto query = [](int x) -> int {
	int sum=0;
	while(x) sum+=c[x],x-=lowbit(x);
	return sum;
};
auto dfs1 = [](auto &&self,int u) -> void {
	s[++top]=u,value[top]=len[0][u];
	for(auto i:v[u]) change(id[1][i],1),change(id[1][i]+size[1][i],-1);
	for(auto i:v1[u]){
		ans[i.qid]+=query(id[1][i.to]);
		int l=1,r=top;
		while(l<r){
			int mid=l+(r-l>>1);
			if(value[mid]>=i.len) r=mid;
			else l=mid+1;
		}
		if(value[l]>=i.len) l--;
		if(l>0&&value[l]<i.len) v2[s[l]].emplace_back(i.qid,i.to);
	}
	for(int i=head[0][u];i;i=e[0][i].nxt) self(self,e[0][i].to);
	top--;
	for(auto i:v[u]) change(id[1][i],-1),change(id[1][i]+size[1][i],1);
};
auto dfs2 = [](auto &&self,int u) -> void {
	for(auto i:v[u]) change(id[1][i],1),change(id[1][i]+size[1][i],-1);
	for(auto i:v2[u]) ans[i.qid]-=query(id[1][i.to]);
	for(int i=head[0][u];i;i=e[0][i].nxt) self(self,e[0][i].to);
	for(auto i:v[u]) change(id[1][i],-1),change(id[1][i]+size[1][i],1);
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s%s",s1,s2),num1[i]=insert(0,s1),num2[i]=insert(1,s2),v[num1[i]].emplace_back(num2[i]);
	build(0),build(1);
	dfs(dfs,0,0),dfs(dfs,1,0);
	for(int T=1;T<=m;T++){
		scanf("%s%s",s1+1,s2+1);
		int len1=strlen(s1+1),len2=strlen(s2+1);
		if(len1!=len2){ans[T]=0;continue;}
		flag[len1+1]=1;
		for(int i=len1;i>=1;i--){
			if(s1[i]!=s2[i]){
				for(int j=i;j>=1;j--) flag[j]=0;
				break;
			}
			flag[i]=1;
		}
		for(int i=1,p1=0,p2=0,nowf=1,lst=0;i<=len1;i++){
			nowf&=(s1[i]==s2[i]);
			if(nowf==1) lst=i;
			p1=son[0][p1][s1[i]-'a'],p2=son[1][p2][s2[i]-'a'];
			if(flag[i+1]) v1[p1].emplace_back(T,p2,i-lst);
		}
	}
	dfs1(dfs1,0);
	dfs2(dfs2,0);
	for(int T=1;T<=m;T++) printf("%lld\n",ans[T]);
	return 0;
}
