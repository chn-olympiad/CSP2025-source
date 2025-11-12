#include<bits/stdc++.h>
#define ll long long
using namespace std;
int rd(){int x=0;char ch=getchar();while(!isdigit(ch)) ch=getchar();while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();return x;}
const int N=5e6+10,M1=1e9+7,M2=998244353,p=137;
int n,q;
pair<int,int> pw[N];
struct node{
	int ha1,ha2;
	
	void init(){ha1=ha2=0;}
	
	void ins(node lst,char c){
		ha1=(1ll*lst.ha1*p+c-'a'+1)%M1;
		ha2=(1ll*lst.ha2*p+c-'a'+1)%M2;
	}
	
	friend bool operator<(const node &x,const node &y){return x.ha1<y.ha1;}
	friend bool operator==(const node &x,const node &y){return x.ha1==y.ha1&&x.ha2==y.ha2;}
	friend node operator*(node x,pair<int,int> mul){return {1ll*x.ha1*mul.first%M1,1ll*x.ha2*mul.second%M2};}
	friend node operator-(node x,node y){return {(x.ha1+M1-y.ha1)%M1,(x.ha2+M2-y.ha2)%M2};}
}H1[N],H2[N],h;
char s1[N],s2[N];
int trie[N][26],dep[N],cnt=1,fail[N],nex[N];
bool vis[N];
map<node,int> mp[N];

void INS(int si,node &h){
	int u=1;
	for(int i=1;i<=si;i++){
		int c=s1[i]-'a';
		if(!trie[u][c]) trie[u][c]=++cnt,dep[cnt]=dep[u]+1;
		u=trie[u][c];
	}
	vis[u]=1;
	mp[u][h]++;
}

void built(){
	for(int i=0;i<26;i++) trie[0][i]=1;
	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0,v;i<26;i++){
			if(!trie[u][i]){
				trie[u][i]=trie[fail[u]][i];
				continue;
			}
			v=trie[u][i];
			fail[v]=trie[fail[u]][i];
			nex[v]=vis[fail[v]]?fail[v]:nex[fail[v]];
			q.push(v);
		}
	}
}

int ans;

node getHa(node h[],int l,int r){
	if(l>r) return {0,0};
	return h[r]-(h[l-1]*pw[r-l+1]);
}

void ask(int si){
	int u=1;
	for(int i=1;i<=si;i++){
		int c=s1[i]-'a';
		u=trie[u][c];
		int v=u;
		do{
			if(vis[v]){
				if(getHa(H1,1,i-dep[v])==getHa(H2,1,i-dep[v])&&getHa(H1,i+1,si)==getHa(H2,i+1,si)){
					node Y=getHa(H2,i-dep[v]+1,i);
					if(mp[v].count(Y)) ans+=mp[v][Y];
				}
			}
			v=nex[v];
		}while(v);
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	pw[0]={1,1};
	for(int i=1;i<N;i++) pw[i].first=1ll*pw[i-1].first*p%M1,pw[i].second=1ll*pw[i-1].second*p%M2;
	for(int i=1,m;i<=n;i++){
		scanf("%s %s",s1+1,s2+1);
		m=strlen(s1+1);
		h.init();
		for(int j=1;j<=m;j++) h.ins(h,s2[j]);
		INS(m,h);
	}
	built();
	for(int i=1;i<=q;i++){
		scanf("%s %s",s1+1,s2+1);
		int m=strlen(s1+1);
		for(int j=1;j<=m;j++){
			H1[j]=H1[j-1];
			H1[j].ins(H1[j],s1[j]);
			H2[j]=H2[j-1];
			H2[j].ins(H2[j],s2[j]);
		}
		ans=0;
		ask(m);
		printf("%d\n",ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a
*/
