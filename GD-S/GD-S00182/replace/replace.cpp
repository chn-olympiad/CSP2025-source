#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<ull,ll> pii;

const int bs=131;
const int bs2=1331;
const ll mod=1e9+7;
const int maxn=2e5+5;
const int maxm=5e6+5;
const int maxz=27;
int ch[maxm][maxz],fail[maxm],cnt=0;
int lst[maxm],dep[maxm];
ull hsh[maxm],pw[maxm];
ll hsh2[maxm],pw2[maxm];
vector<pii> vec[maxm];
char ch1[maxm],ch2[maxm];
queue<int> que;
struct edge{
	int to,nxt;
}e[maxm];
int head[maxm],len;

pii gethsh(int l,int r){
	return make_pair(hsh[r]-hsh[l-1]*pw[r-l+1],(hsh2[r]-hsh2[l-1]*pw2[r-l+1]%mod+mod)%mod);
}

inline void init(){
	pw[0]=pw2[0]=1;
	for(int i=1;i<=cnt;i++){
		pw[i]=pw[i-1]*bs;
		pw2[i]=pw2[i-1]*bs2%mod;
	}
	memset(head,-1,sizeof(head));
	len=0;
}
void add(int u,int v){
	e[++len].to=v;
	e[len].nxt=head[u];
	head[u]=len;
}

void ins(int n,pii hs){
	int now=0;
	for(int i=1;i<=n;i++){
		int t=ch1[i]-'a';
		if(!ch[now][t]){
			ch[now][t]=++cnt;
			vec[cnt].clear();
		}
		now=ch[now][t];
	}
	lst[now]=now;
	vec[now].push_back(hs);
}
void getfail(){
	while(!que.empty()) que.pop();
	for(int i=0;i<26;i++){
		if(ch[0][i]){
			dep[ch[0][i]]=1;
			que.push(ch[0][i]);
			add(0,ch[0][i]);
			// printf("0 %d %c\n",ch[0][i],i+'a');
		}
	}
	while(!que.empty()){
		int u=que.front();
		que.pop();
		for(int j=0;j<26;j++){
			if(ch[u][j]){
				fail[ch[u][j]]=ch[fail[u]][j];
				add(fail[ch[u][j]],ch[u][j]);
				dep[ch[u][j]]=dep[u]+1;
				que.push(ch[u][j]);
				// printf("%d %d %c\n",u,ch[u][j],j+'a');
			}else ch[u][j]=ch[fail[u]][j];
		}
	}
}

void dfs(int u){
	if(!lst[u]) lst[u]=lst[fail[u]];
	for(int i=head[u];i!=-1;i=e[i].nxt){
		int v=e[i].to;
		// printf("kk%d %d\n",u,v);
		dfs(v);
	}
}

int main(){
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s %s",ch1+1,ch2+1);
		ull hs=0;
		ll hs2=0;
		int m=strlen(ch1+1);
		for(int j=1;j<=m;j++){
			hs=hs*bs+ch2[j]-'a';
			hs2=(hs2*bs2%mod+ch2[j]-'a')%mod;
		}
		ins(m,make_pair(hs,hs2));
	}
	
	init();
	getfail();
	dfs(0);
	
	while(q--){
		scanf("%s %s",ch1+1,ch2+1);
		if(strlen(ch1+1)!=strlen(ch2+1)){
			puts("0");
			continue;
		}
		int res=0,l=0,r=0;
		int m=strlen(ch1+1);
		for(int i=1;i<=m;i++){
			if(ch1[i]!=ch2[i]){
				l=i;
				break;
			}
		}
		for(int i=m;i>=1;i--){
			if(ch1[i]!=ch2[i]){
				r=i;
				break;
			}
		}
		hsh[0]=hsh2[0]=0;
		for(int i=1;i<=m;i++){
			hsh[i]=hsh[i-1]*bs+ch2[i]-'a';
			hsh2[i]=(hsh2[i-1]*bs2%mod+ch2[i]-'a')%mod;
		}
		int now=0;
		// printf("%s %s %d %d\n",ch1+1,ch2+1,l,r);
		for(int i=1;i<=m;i++){
			int t=ch1[i]-'a';
			now=ch[now][t];
			if(i<r) continue;
			// printf("kk%d %d ",now,lst[now]);
			int tmp=lst[now];
			while(dep[tmp]>=(i-l+1)){
				// printf("pp%d %d\n",tmp,(int)vec[tmp].size());
				for(pii x : vec[tmp]){
					// printf("%d %d\n",i-dep[tmp]+1,i);
					if(x==gethsh(i-dep[tmp]+1,i)) res++;
				}
				tmp=lst[fail[tmp]];
			}
			// printf("%d\n",res);
		}
		printf("%d\n",res);
	}
	
	return 0;
}