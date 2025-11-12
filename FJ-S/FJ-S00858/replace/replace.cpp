#include<bits/stdc++.h>
using namespace std;
const int N=6e6+100;
char s[N],t[N];
int ch[2][N][26];
int dep[2][N];
bool vis[N];
vector<int > e[2][N];
int fail[2][N];
int tot[2];
bool pre[N],suf[N];
void insert(int opt,int x){
	int p=0,n=strlen(s+1);
	dep[opt][p]=1;
	for(int i=1;i<=n;i++){
		if(!ch[opt][p][s[i]-'a'])ch[opt][p][s[i]-'a']=++tot[opt];
		dep[opt][ch[opt][p][s[i]-'a']]=dep[opt][p]+1;
		p=ch[opt][p][s[i]-'a'];
	}
	e[opt][p].push_back(x);
}
queue<int> q;
void build(int opt){
	for(int i=0;i<=25;i++){
		if(ch[opt][0][i])q.push(ch[opt][0][i]);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<=25;i++){
			if(!ch[opt][x][i])ch[opt][x][i]=ch[opt][fail[opt][x]][i];
			else {
				fail[opt][ch[opt][x][i]]=ch[opt][fail[opt][x]][i];
				q.push(ch[opt][x][i]);
			}
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert(0,i);
		scanf("%s",s+1);
		insert(1,i);
	}
	build(0);
	build(1);
	while(q--){
		scanf("%s%s",s+1,t+1);
		int len=strlen(s+1);
		int p0=0,p1=0,ans=0;
		bool flag=0;
		for(int i=len;i>=1;i--){
			if(s[i]==t[i]&&flag==0)suf[i]=1;
			else flag=1,suf[i]=0;
		}
		flag=0;
		pre[0]=1,suf[len+1]=1;
		for(int i=1;i<=len;i++){
			if(s[i]==t[i]&&flag==0)pre[i]=1;
			else flag=1,pre[i]=0;
		}
		for(int i=1;i<=len;i++){
			p0=ch[0][p0][s[i]-'a'];
			p1=ch[1][p1][t[i]-'a'];
			int x=p0,y=p1;
			while(x&&y){
				if(dep[0][x]>dep[1][y])
					x=fail[0][x];
				else if(dep[0][x]<dep[1][y])
					y=fail[1][y];
				else {
					for(int v:e[0][x])vis[v]=1;
					for(int v:e[1][y]){
						if(vis[v]){
							int www=dep[1][y]-1;
							ans+=(pre[i-www]&&suf[i+1]);
						}
					}
					for(int v:e[0][x])vis[v]=0;
					x=fail[0][x];
					y=fail[1][y];
				}
				
			}
		} 
		printf("%d\n",ans);
	}
	return 0;
}
