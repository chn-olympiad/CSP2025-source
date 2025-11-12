#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vec vector<int>
#define M 998244353
#define pi pair<int,int>
void in(int &x){
	x=0;int f=1;char c=getchar();
	while((c>'9'||c<'0')&&c!='-')c=getchar();
	if(c=='-')f=-1,c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	x*=f;
}
int t,n,m,k,x,y,cnt[5200005],res[200005];
char s1[5200005],s2[5200005],s[5200005];
int tot,tr[5200005][27];
vector<int>d[5200005],q[5200005],g[5200005];
string S[200005],T[200005];
void ins(int id){
	int u=0;
	for(int i=1;i<=k;i++){
		int c=s[i]-'a';
		if(!tr[u][c])tr[u][c]=++tot,g[u].pb(tot);
		u=tr[u][c];
	}
	d[u].pb(id);
}
void get(int id){
	int u=0,ans=0;
	for(int i=1;i<=k;i++){
		int c=s[i]-'a';
		if(!tr[u][c])break;
		u=tr[u][c];
	}
	q[u].pb(id);
}
void add(int id,int x){
	int u=0,len=S[id].size();
	for(int i=0;i<len;i++){
		int c=S[id][i]-'a';
		if(!tr[u][c])tr[u][c]=++tot;
		u=tr[u][c];
	}
	cnt[u]+=x;
}
int query(int id){
	int u=0,len=T[id].size(),ans=cnt[0];
	for(int i=0;i<len;i++){
		int c=T[id][i]-'a';
		if(!tr[u][c])break;
		u=tr[u][c];ans+=cnt[u];
	}
	return ans;
}
void dfs(int u){
	for(int x:d[u])add(x,1);
	for(int x:q[u])res[x]=query(x);
	for(int v:g[u])dfs(v);
	for(int x:d[u])add(x,-1);
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	in(n);in(m);
	for(int i=1;i<=n;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),x=0,y=0;
		for(int j=1;j<=len;j++)if(s1[j]!=s2[j]){x=j;break;}
		for(int j=len;j>=1;j--)if(s1[j]!=s2[j]){y=j;break;}
		if(!x&&!y){continue;}
	    k=0;for(int j=x;j<=y;j++)s[++k]=s1[j];
	    for(int j=x;j<=y;j++)s[++k]=s2[j];
	    s[++k]=26+'a';for(int j=x-1;j>=1;j--)s[++k]=s1[j];
	    for(int j=y+1;j<=len;j++)S[i]+=s1[j];
	    ins(i);
	}
	for(int i=1;i<=m;i++){
		scanf("%s%s",s1+1,s2+1);
		int len=strlen(s1+1),l=strlen(s2+1),x=0,y=0;
		if(len!=l)continue;
		for(int j=1;j<=len;j++)if(s1[j]!=s2[j]){x=j;break;}
		for(int j=len;j>=1;j--)if(s1[j]!=s2[j]){y=j;break;}
		if(!x&&!y){continue;}
	    k=0;for(int j=x;j<=y;j++)s[++k]=s1[j];
	    for(int j=x;j<=y;j++)s[++k]=s2[j];
	    s[++k]=26+'a';for(int j=x-1;j>=1;j--)s[++k]=s1[j];
	    for(int j=y+1;j<=len;j++)T[i]+=s1[j];
	    get(i);
	}
	memset(tr,0,sizeof tr);tot=0;
	dfs(0);
	for(int i=1;i<=m;i++)printf("%d\n",res[i]);
}