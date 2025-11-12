#include<bits/stdc++.h>

#define For(i,j,k) for(int i=(j);i<=(k);i++)
#define Fol(i,j,k) for(int i=(j);i>=(k);i--)
#define vi vector<int>
#define pi pair<int,int>
#define se second
#define fi first
#define ll long long
#define all(x) x.begin(),x.end()
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

#define N 5000005
#define M 500005

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9')f=(ch=='-'?-1:f),ch=getchar();
	while(ch>='0' && ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
void write(ll x){
	if(x<0)x=-x,putchar('-');
	if(x/10)write(x/10);
	putchar(x%10+'0');
}

char s[N],s2[N];
int n,q;

int tot=1,dfn=0,cnt=0;
pi loc[M];
int nex[N][26];
int L[N],R[N],mar[N],fail[N],dep[N],f[N][21],esiz[N];
vector<pi> lk[M];
queue<int> Q1;
basic_string<int> e[N];
void dfs(int x,int las){
	f[x][0]=las;if(lk[mar[x]].size())las=x;
	For(i,1,20)f[x][i]=f[f[x][i-1]][i-1];
	for(auto v:e[x])dfs(v,las);
}
void dfs3(int x){
	L[x]=R[x]=++dfn;
	for(auto v:e[x])esiz[v]+=esiz[x],dfs3(v),R[x]=R[v];
}
ll ans[M];
void build(){
	For(j,1,n){
		scanf("%s",s+1);scanf("%s",s2+1);
		int p=1,len=strlen(s+1),flag=0;
		For(i,1,len)if(s[i]==s2[i])flag=1;
		For(i,1,len){
			int it=s[i]-'a';
			if(!nex[p][it])nex[p][it]=++tot,dep[tot]=dep[p]+1;
			p=nex[p][it];
		}
		loc[j].fi=p;p=1;
		For(i,1,len){
			int it=s2[i]-'a';
			if(!nex[p][it])nex[p][it]=++tot,dep[tot]=dep[p]+1;
			p=nex[p][it];
		}
		loc[j].se=p;
		if(!flag)esiz[p]++;
	}
	fail[1]=1;
	For(i,0,25){
		if(!nex[1][i]){nex[1][i]=1;continue;}
		int u=nex[1][i];fail[u]=1;e[1]+=u;Q1.push(u);
	}
	while(Q1.size()){
		int u=Q1.front();Q1.pop();
		For(i,0,25){
			if(nex[u][i]){
				fail[nex[u][i]]=nex[fail[u]][i];
				e[fail[nex[u][i]]]+=nex[u][i];
				Q1.push(nex[u][i]);
			}
			else nex[u][i]=nex[fail[u]][i];
		}
	}
	dfs3(1);
	For(i,1,n){
		if(!mar[loc[i].fi])mar[loc[i].fi]=++cnt;
		lk[mar[loc[i].fi]].pb(mp(L[loc[i].se],R[loc[i].se]));
	}
	dfs(1,1);
}

struct Node{
	int id,coef,pos;
	Node(int id=0,int coef=0,int pos=0):id(id),coef(coef),pos(pos){}
};
vector<Node> Q[N];

struct BIT{
	int K[N];
	void add(int x,int val){for(;x<N;x+=(x&(-x)))K[x]+=val;}
	int ask(int x){int ans=0;for(;x;x-=((x&(-x))))ans+=K[x];return ans;}
}T;

void dfs2(int x){
	for(auto w:lk[mar[x]]){
		int l=w.fi,r=w.se;
		//cerr<<l<<' '<<r<<"***"<<endl;
		T.add(l,1);T.add(r+1,-1);
		//if(x==15028)cerr<<l<<' '<<r<<endl;
		//659367
	}
	//if(x==6)cerr<<T.ask(17)<<endl;
	//cerr<<x<<endl;
	for(auto tmp:Q[x]){
		int id=tmp.id,coef=tmp.coef,pos=tmp.pos;
		ans[id]+=T.ask(pos)*coef;
	}
//	if(L[x]<=453740 && R[x]>=453740){
//		cerr<<x<<' '<<mar[x]<<' '<<lk[mar[x]].size()<<' '<<dep[x]<<' '<<T.ask(659367)<<endl;
//	}
	for(auto v:e[x]){dfs2(v);}
	//if(x==15028)cerr<<L[15028]<<endl;
	for(auto w:lk[mar[x]]){
		int l=w.fi,r=w.se;
		T.add(l,-1);T.add(r+1,1);
	}
}

int main(){

	double st=clock();
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	n=read(),q=read();
	build();
	For(i,1,q){
		scanf("%s",s+1);scanf("%s",s2+1);
		int len=strlen(s+1),lpos=len+1,rpos=-1;
		For(j,1,len){
			if(s[j]!=s2[j])lpos=min(lpos,j),rpos=j;
		}
		if(rpos==-1){
			int p=1;
			For(j,1,len){
				int it=s[j]-'a';p=nex[p][it];
				ans[i]+=esiz[p];
			}
			continue;
		}
		int p=1,p2=1;
		For(j,1,len){
			int it=s[j]-'a',it2=s2[j]-'a';p=nex[p][it];p2=nex[p2][it2];
			if(j<rpos)continue;
			int minl=j-lpos+1;
			
			if(dep[p]<minl || dep[p2]<minl)continue;
			//if(i==103)cerr<<p<<' '<<dep[p]<<' '<<p2<<' '<<dep[p2]<<endl;
			Q[p].pb(Node(i,1,L[p2]));
			int tmp=p;
			Fol(k,20,0){
				if(dep[f[tmp][k]]>=minl)tmp=f[tmp][k];
				//if(i==101 && k==0)cerr<<dep[f[tmp][k]]<<' '<<minl<<endl;
			}
			//if(i==101)cerr<<minl<<' '<<p<<' '<<tmp<<' '<<dep[f[tmp][0]]<<endl;
			//cerr<<p<<' '<<p2<<' '<<L[p2]<<' '<<i<<' '<<dep[p]<<' '<<dep[p2]<<' '<<minl<<' '<<f[tmp][0]<<endl;
			if(f[tmp][0]!=1)Q[f[tmp][0]].pb(Node(i,-1,L[p2]));
		}
	}
	dfs2(1);
	For(i,1,q)write(ans[i]),putchar('\n');
	//cerr<<(clock()-st)*1.0/CLOCKS_PER_SEC*1000<<"ms"<<endl;
	return 0;
}
