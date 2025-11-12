#include<bits/stdc++.h>
#define N 2500007
#define ll long long
#define fi first
#define se second

using namespace std;

int n,q,ans[N];
pair<int,int> pos[N]; 
ll base=131,mod=998244353;
map<ll,vector<pair<string,int> > > mp;

int tot,tr[N][26],fail[N],cnt[N];
vector<int> G[N]; 

void add(string s){
	int len=s.size(),cur=0;
	for(int i=0;i<len;i++){
		int c=s[i]-'a';
		if(!tr[cur][c]) tr[cur][c]=++tot;
		cur=tr[cur][c];
	}
	cnt[cur]++;
}
void build(){
	queue<int> q; 
	for(int i=0;i<26;i++) if(tr[0][i]) q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		G[fail[u]].push_back(u);
		for(int i=0;i<26;i++){
			if(tr[u][i]) fail[tr[u][i]]=tr[fail[u]][i],q.push(tr[u][i]);
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
void dfs(int u){
	for(int v:G[u]) cnt[v]+=cnt[u],dfs(v);
}
int query(string s,int l,int r){
	int cur=0,ret=0;
	for(int i=l;i<=r;i++){
		int c=s[i]-'a';
		cur=tr[cur][c];
		ret+=cnt[cur];
	}
	return ret;
} 

int main()
{
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s,t;cin>>s>>t;
		int len=s.size(),l=0,r=len-1;
		while(l<len&&s[l]==t[l]) l++;
		if(l==len) continue;
		while(s[r]==t[r]) r--;
		ll hs=0;
		for(int i=l;i<=r;i++) hs=(hs*base+(s[i]-'a')*26+t[i]-'a')%mod;
		mp[hs].push_back({s,0});
	}
	for(int i=1;i<=q;i++){
		string s,t;cin>>s>>t;
		int len=s.size(),l=0,r=len-1;
		while(l<len&&s[l]==t[l]) l++;
		while(s[r]==t[r]) r--;
		ll hs=0;
		for(int i=l;i<=r;i++) hs=(hs*base+(s[i]-'a')*26+t[i]-'a')%mod;
		pos[i]={l+1,r-1};
		mp[hs].push_back({s,i});
	}
	for(auto p:mp){
		auto S=p.se;
//		for(auto p:S) cout<<p.fi<<' '<<p.se<<'\n';puts("");
		for(auto p:S) if(!p.se) add(p.fi);
		build();
		dfs(0);
		for(auto p:S) if(p.se){
			ans[p.se]+=query(p.fi,0,p.fi.size()-1);
			ans[p.se]-=query(p.fi,0,pos[p.se].se);
			ans[p.se]-=query(p.fi,pos[p.se].fi,p.fi.size()-1);
			ans[p.se]+=query(p.fi,pos[p.se].fi,pos[p.se].se); 
		}
		while(tot) memset(tr[tot],0,26<<2),fail[tot]=cnt[tot]=0,G[tot].clear(),tot--;
		memset(tr[0],0,26<<2),fail[0]=cnt[0]=0,G[0].clear();
	}
	for(int i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
