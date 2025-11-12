#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int n,q,tot,tots,tott,ttt,ls[5200001],rs[5200001],s[5200001][26],t[5200001][26],head[5200001],nex[400001],ver[400001],idx[400001];
int ans[200001];
char S[5000001],T[5000001];
map <pair<ll,ll>,int> rt[2];
int B[5200001];
void add(int i,int v){
	for(;i<=tott;i+=i&-i) B[i]+=v;
}
int ask(int i){
	int s=0;
	for(;i>0;i-=i&-i) s+=B[i];
	return s;
}
void dfs(int x){
	ls[x]=++ttt;
	for(int i=0;i<26;i++) if(t[x][i]) dfs(t[x][i]);
	rs[x]=ttt;
}
void bfs(int x){
	for(int i=head[x];i;i=nex[i]){
		if(!idx[i]){
			add(ls[ver[i]],1);
			add(rs[ver[i]]+1,-1);
		}
	}
	for(int i=head[x];i;i=nex[i]){
		if(idx[i]){
			ans[idx[i]]=ask(ls[ver[i]]);
		}
	}
	for(int i=0;i<26;i++) if(s[x][i]) bfs(s[x][i]);
	for(int i=head[x];i;i=nex[i]){
		if(!idx[i]){
			add(ls[ver[i]],-1);
			add(rs[ver[i]]+1,1);
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s%s",S+1,T+1);
		int m=strlen(S+1),x=0,y=m+1;
		while(x<m&&S[x+1]==T[x+1]) x++;
		while(y>1&&S[y-1]==T[y-1]) y--;
		if(x>y) continue;
		ll ss=0,st=0;
		for(int j=x+1;j<y;j++){
			ss=ss*131+S[j]-50;
			st=st*131+T[j]-50;
		}
		if(!rt[0][{ss,st}]) rt[0][{ss,st}]=++tots,rt[1][{ss,st}]=++tott;
		int p=rt[0][{ss,st}];
		for(int j=x;j>=1;j--){
			int c=S[j]-'a';
			if(!s[p][c]) s[p][c]=++tots;
			p=s[p][c];
		}
		int lst=p;
		p=rt[1][{ss,st}];
		for(int j=y;j<=m;j++){
			int c=S[j]-'a';
			if(!t[p][c]) t[p][c]=++tott;
			p=t[p][c];
		}
		ver[++tot]=p;
		nex[tot]=head[lst];
		head[lst]=tot;
	}
	for(auto i:rt[1]) dfs(i.second);
	for(int i=1;i<=q;i++){
		scanf("%s%s",S+1,T+1);
		int m=strlen(S+1),x=0,y=m+1;
		while(x<m&&S[x+1]==T[x+1]) x++;
		while(y>1&&S[y-1]==T[y-1]) y--;
		ll ss=0,st=0;
		for(int j=x+1;j<y;j++){
			ss=ss*131+S[j]-50;
			st=st*131+T[j]-50;
		}
		if(!rt[0].count({ss,st})||!rt[1].count({ss,st})) continue;
		int p=rt[0][{ss,st}];
		for(int j=x;j>=1;j--){
			int c=S[j]-'a';
			if(!s[p][c]) break;
			p=s[p][c];
		}
		int lst=p;
		p=rt[1][{ss,st}];
		for(int j=y;j<=m;j++){
			int c=S[j]-'a';
			if(!t[p][c]) break;
			p=t[p][c];
		}
		ver[++tot]=p;
		nex[tot]=head[lst];
		idx[tot]=i;
		head[lst]=tot;
	}
	for(auto i:rt[0]) bfs(i.second);
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
