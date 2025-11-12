#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod0=998244353,mod1=1e9+7,sed=131;
const int N=400005,L=10000005;
int n,m,cnt,ans[N];
char str[L];
int pos[N][2],len[N][2];
int fi[N],ed[N];
char get(int x,int o,int i){return str[pos[x][o]+i];}
pair<pair<int ,int > ,int > a[N];

struct BIT{
	int ln,c[N];
	void init(int _ln){
		ln=_ln;
		for(int i=0;i<=ln;i++) c[i]=0;
	}
	void add(int x,int y){
		for(;x<=ln;x+=x&(-x)) c[x]+=y;
	}
	int ask(int x){
		int res=0;
		for(;x>0;x-=x&(-x)) res+=c[x];
		return res;
	}
}B;

int son[L][26],pn[N];
bool vis[L];
int dfn[L],out[L],tot,cnk;
void dfs(int u){
	dfn[u]=cnk+1;
	if(vis[u]) cnk++;
	for(int i=0;i<26;i++)
		if(son[u][i]) dfs(son[u][i]);
	out[u]=cnk;
}
int pl[N],pr[N];
vector<int > ad[N],dl[N],qr[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n+m;i++){
		scanf("%s",str+pos[i][0]);
		for(pos[i][1]=pos[i][0];'a'<=str[pos[i][1]]&&str[pos[i][1]]<='z';pos[i][1]++);
		len[i][0]=pos[i][1]-pos[i][0];
		scanf("%s",str+pos[i][1]);
		for(pos[i+1][0]=pos[i][1];'a'<=str[pos[i+1][0]]&&str[pos[i+1][0]]<='z';pos[i+1][0]++);
		len[i][1]=pos[i+1][0]-pos[i][1];
	}
	for(int i=1;i<=n+m;i++){
		if(len[i][0]!=len[i][1]) continue;
		fi[i]=ed[i]=-1;
		for(int j=0;j<len[i][0];j++)
			if(get(i,0,j)!=get(i,1,j)){
				ed[i]=j;
				if(fi[i]<0) fi[i]=j;
			}
		if(fi<0) continue;
		int hsh0=0,hsh1=0;
		for(int j=fi[i];j<=ed[i];j++){
			hsh0=(1ll*hsh0*sed+get(i,0,j))%mod0;
			hsh0=(1ll*hsh0*sed+get(i,1,j))%mod0;
			hsh1=(1ll*hsh1*sed+get(i,0,j))%mod1;
		}
		for(int j=fi[i];j<=ed[i];j++)
			hsh1=(1ll*hsh1*sed+get(i,1,j))%mod1;
		a[++cnt]={{hsh0,hsh1},i};
	}
	sort(a+1,a+cnt+1);
	for(int l=1,r;l<=cnt;l=r+1){
		for(r=l;r<cnt&&a[r+1].fi==a[l].fi;r++);
		for(int i=1;i<=tot;i++){
			vis[i]=0;
			for(int j=0;j<26;j++) son[i][j]=0;
		}
		tot=1;
		for(int i=l;i<=r;i++){
			int now=1,u=a[i].se;
			for(int j=fi[u]-1;j>=0;j--){
				int op=get(u,0,j)-'a';
				if(!son[now][op]) son[now][op]=++tot;
				now=son[now][op];
			}
			pn[i]=now;
			vis[now]=1;
		}
		cnk=0;dfs(1);
		for(int i=l;i<=r;i++){
			pl[i]=dfn[pn[i]];
			pr[i]=out[pn[i]];
		}
		B.init(cnk);
		for(int i=1;i<=tot;i++){
			vis[i]=0;
			for(int j=0;j<26;j++) son[i][j]=0;
		}
		tot=1;
		for(int i=l;i<=r;i++){
			int now=1,u=a[i].se;
			for(int j=ed[u]+1;j<len[u][0];j++){
				int op=get(u,0,j)-'a';
				if(!son[now][op]) son[now][op]=++tot;
				now=son[now][op];
			}
			pn[i]=now;
			vis[now]=1;
		}
		cnk=0;dfs(1);
		for(int i=l;i<=r;i++){
			int u=a[i].se;
			if(u<=n){
				ad[dfn[pn[i]]].push_back(i);
				dl[out[pn[i]]].push_back(i);
			}
			else qr[dfn[pn[i]]].push_back(i);
		}
		for(int i=1;i<=cnk;i++){
			for(int x:ad[i]){
				B.add(pl[x],1);
				B.add(pr[x]+1,-1);
			}
			for(int x:dl[i-1]){
				B.add(pl[x],-1);
				B.add(pr[x]+1,1);
			}
			for(int x:qr[i]){
				int u=a[x].se;
				ans[u]=B.ask(pl[x]);
			}
		}
		for(int i=0;i<=cnk;i++){
			ad[i].clear();
			dl[i].clear();
			qr[i].clear();
		}
	}
	for(int i=n+1;i<=n+m;i++) printf("%d\n",ans[i]);
} 
