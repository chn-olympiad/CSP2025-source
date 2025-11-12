#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=2e6+10,L=5e6+10;
int n,q,ans[N];string s1[N],s2[N],T1[N],T2[N],t1,t2;
bool check(string &str){
	int sum=0;
	for(char ch:str){
		if(ch>'b')return false;
		if(ch=='b')sum++;
	}
	return sum==1;
}
namespace solve1{
	struct node{int son[30],fa,len;}tr[L];int tot,rot;
	int ls1[N],ls2[N];vector<int>E[L],G[L];
	int F[L][25],sum[L],dfn[L],siz[L];
	vector<pii >ak[L];
	int insert(string s){
		int x=rot;
		for(int i=0;i<s.size();i++){
			int y=s[i]-'a';
			if(!tr[x].son[y]){
				tr[x].son[y]=++tot;
				tr[tot].len=tr[x].len+1;
			}
			x=tr[x].son[y];
		}
		return x;
	}
	void dfs(int u){
		// cout<<u<<" "<<tr[u].fa<<endl;
		dfn[u]=++dfn[0],siz[u]=1;
		F[u][0]=tr[u].fa;sum[u]+=sum[tr[u].fa];
		for(int i=1;i<=22;i++)F[u][i]=F[F[u][i-1]][i-1];
		for(int v:E[u])dfs(v),siz[u]+=siz[v];
	}
	void init(){
		queue<int>q;
		// for(int i=1;i<=tot;i++){
		// 	cout<<i<<" :";
		// 	for(int j=0;j<26;j++)if(tr[i].son[j])
		// 		cout<<(char)(j+'a')<<" "<<tr[i].son[j]<<"  ";;
		// 	cout<<endl;
		// }
		tr[rot].fa=rot;
		for(int i=0;i<26;i++){
			int &v=tr[rot].son[i];
			if(!v)v=rot;
			else q.push(v),tr[v].fa=rot;
		}
		while(!q.empty()){
			int u=q.front();q.pop();
			E[tr[u].fa].push_back(u);
			// cout<<"! "<<u<<" "<<tr[u].fa<<endl;
			for(int i=0;i<26;i++){
				int &v=tr[u].son[i];
				if(v){
					q.push(v);tr[v].fa=tr[tr[u].fa].son[i];
				}
				else v=tr[tr[u].fa].son[i];
			}
		}
		// cerr<<tot<<endl;
		dfs(rot);
	}
	int btr[L];int lw(int x){return -x&x;}
	void add(int x,int y){for(;x<=tot;x+=lw(x))btr[x]+=y;}
	int ask(int x){int s=0;for(;x;x-=lw(x))s+=btr[x];;return s;}
	void dfs2(int u){
		for(int i:G[u])add(dfn[i],1),add(dfn[i]+siz[i],-1);
		for(pii p:ak[u]){
			int fl=p.se<0?-1:1;
			ans[p.se*fl]+=fl*ask(dfn[p.fi]);
		}
		for(int v:E[u])dfs2(v);
		for(int i:G[u])add(dfn[i],-1),add(dfn[i]+siz[i],1);
	}
	void sol(){
		rot=++tot;
		for(int i=1;i<=n;i++){
			ls1[i]=insert(s1[i]);
			ls2[i]=insert(s2[i]);
			if(ls1[i]==ls2[i])sum[ls1[i]]++;
			G[ls1[i]].push_back(ls2[i]);
		}
		init();
		// return 0;
		for(int t=1;t<=q;t++){
			t1=T1[t],t2=T2[t],t1=" "+t1,t2=" "+t2;
			if(t1.size()!=t2.size()){
				ans[t]=0;continue;
			}
			int len=t1.size()-1,lp=0,rp=len+1;
			while(lp+1<=len&&t1[lp+1]==t2[lp+1])lp++;
			while(rp>1&&t1[rp-1]==t2[rp-1])rp--;
			if(lp==len){
				int x=rot;
				for(int i=1;i<=len;i++){
					x=tr[x].son[t1[i]-'a'];
					ans[t]+=sum[x];
				}
				continue;
			}
			int x=rot,y=rot;
			for(int i=1;i<=len;i++){
				x=tr[x].son[t1[i]-'a'],y=tr[y].son[t2[i]-'a'];
				if(i<rp-1||min(tr[x].len,tr[y].len)<i-lp)continue;
				int xx=x,yy=y;
				for(int j=22;j>=0;j--){
					if(tr[F[xx][j]].len>=i-lp)xx=F[xx][j];
				}
				for(int j=22;j>=0;j--){
					if(tr[F[yy][j]].len>=i-lp)yy=F[yy][j];
				}
				// if(t==101){
				// 	cerr<<t<<" "<<i-lp<<" "<<x<<" "<<y<<" "<<xx<<" "<<yy<<endl;
				// 	cerr<<tr[x].len<<" "<<tr[y].len<<endl;
				// 	exit(0);
				// }
				if(F[yy][0])ak[x].push_back({F[yy][0],-t});
				ak[x].push_back({y,t});
				if(F[xx][0]){
					if(F[yy][0])
						ak[F[xx][0]].push_back({F[yy][0],t});
					ak[F[xx][0]].push_back({y,-t});
				}
			}
		}
		dfs2(rot);
		for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	}
}
namespace solve2{
	void sol(){

	}
}
int main(){
	// freopen("1.in","r",stdin);
	// freopen("1.out","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		flag&=check(s1[i])&check(s2[i]);
	}
	for(int i=1;i<=q;i++){
		cin>>T1[i]>>T2[i];
		flag&=check(T1[i])&check(T2[i]);
	}
	// if(flag){solve2::sol();return 0;}
	solve1::sol();
	return 0;
}