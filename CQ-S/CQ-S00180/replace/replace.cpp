#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5,mod1=1e9+7,mod2=998244353;
struct trie{
	int son[26],fail,dep;
	map<pair<int,int>,int> flag;
}t[N];
int n,m,cnt=1;
int a[N][2],p[N][2];
inline int hax(int l,int r,int op){
	if(!l) return a[r][op];
	if(!op) return (1ll*a[r][op]-1ll*a[l-1][op]*p[r-l+1][op]%mod1+1ll*mod1)%mod1;
	return (1ll*a[r][op]-1ll*a[l-1][op]*p[r-l+1][op]%mod2+1ll*mod2)%mod2;
}
void insert(string s,string g){
	int l=s.length();
	a[0][0]=a[0][1]=g[0]-'a'+1;
	for(int i=1;i<l;i++){
		a[i][0]=(a[i-1][0]*13131ll+g[i]-'a'+1)%mod1;
		a[i][1]=(a[i-1][1]*13131ll+g[i]-'a'+1)%mod2;
	}
	int u=1;
	for(int i=0;i<l;i++){
		int v=s[i]-'a';
		if(!t[u].son[v]) t[u].son[v]=++cnt;
		u=t[u].son[v];
	}
	++t[u].flag[{hax(0,l-1,0),hax(0,l-1,1)}];
}
queue<int> q;
void get_fail(){
	while(!q.empty()) q.pop();
	for(int i=0;i<26;i++) t[0].son[i]=1;
	t[1].fail=t[1].dep=0;
	q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			int v=t[u].son[i],f=t[u].fail;
			if(!v){
				t[u].son[i]=t[f].son[i];
				continue;
			}
			t[v].fail=t[f].son[i];
			t[v].dep=t[u].dep+1;
			q.push(v);
		}
	}
}
string s,g;int ls,lg,L,R,ans;
void work(){
	int u=1;
	for(int i=0;i<ls;i++){
		int v=s[i]-'a';
		u=t[u].son[v];
		if(i>=R){
			if(t[u].dep<i-L+1) return;
			int uu=u;
			while(t[uu].dep>=i-L+1){
				ans+=t[uu].flag[{hax(i-t[uu].dep+1,i,0),hax(i-t[uu].dep+1,i,1)}];
				uu=t[uu].fail;
			}
		}
	}
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	p[0][0]=p[0][1]=1;
	for(int i=1;i<N;i++) p[i][0]=p[i-1][0]*13131ll%mod1,p[i][1]=p[i-1][1]*13131ll%mod2;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s>>g;
		insert(s,g);
	}
	get_fail();
	while(m--){
		cin>>s>>g;
		ls=s.length(),lg=g.length();
		a[0][0]=a[0][1]=g[0]-'a'+1;
		for(int i=1;i<ls;i++){
			a[i][0]=(a[i-1][0]*13131ll+g[i]-'a'+1)%mod1;
			a[i][1]=(a[i-1][1]*13131ll+g[i]-'a'+1)%mod2;
		}
		if(ls!=lg){
			cout<<"0\n";
			continue;
		}
		L=R=-1;
		for(int i=0;i<ls;i++){
			if(s[i]!=g[i]){
				if(L==-1) L=i;
				R=i;
			}
		}
		ans=0;
		work();
		cout<<ans<<'\n';
	}
	return 0;
}
