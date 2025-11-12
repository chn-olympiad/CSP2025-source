#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=5e5+5,MR=6e6+5;
bool Mbe;
int n,m,q,k=1,tot,pl[MAXN],pr[MAXN],ans[MAXN];bool vis[MR];
string s1[MAXN],s2[MAXN],q1[MAXN],q2[MAXN];
int in[MR],out[MR]; 
int trie[MR][26];
vector<array<int,2>> qrs[MAXN],ops[MAXN];
struct BIT{
int a[MAXN];
void add(int x,int v){while(x<=tot)a[x]+=v,x+=(x&-x);}
int ask(int x){int r=0;while(x)r+=a[x],x-=(x&-x);return r;}
}T;
bool Med;
string R(string s){
	reverse(s.begin(),s.end());
	return s;
}
int add(int u,string s){
//	cerr<<"add "<<u<<' '<<s<<endl; 
	for(auto ch:s){
		int c=ch-'a';
		if(!trie[u][c]) trie[u][c]=++k;
		u=trie[u][c];
	}
	return u;
}
int find(int u,string s){
	for(auto ch:s){
		int c=ch-'a';
		if(!trie[u][c]) return 0;
		u=trie[u][c];
	}
	return u;
}
void dfs(int u){
	in[u]=tot+1;
	if(vis[u]) tot++;
	for(int i=0;i<26;i++) if(trie[u][i]) dfs(trie[u][i]);
	out[u]=tot;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//	cerr<<"Memory: "<<(&Mbe-&Med)*1.0/1024/1024<<"\n";
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
	for(int i=1;i<=q;i++) cin>>q1[i]>>q2[i];
	vector<int> rts;
	for(int i=1;i<=q;i++) if(q1[i].size()==q2[i].size()&&q1[i]!=q2[i]){
		int l=0,r=q1[i].size()-1;
		while(q1[i][l]==q2[i][l]) l++;
		while(q1[i][r]==q2[i][r]) r--;
		int u=add(1,q1[i].substr(l,r-l+1)+q2[i].substr(l,r-l+1));
//		cerr<<q1[i].substr(l,r-l+1)+q2[i].substr(l,r-l+1)<<'\n';
		if(!in[u]) in[u]=++k,out[u]=++k,rts.push_back(k-1),rts.push_back(k);
		pl[i]=add(in[u],R(q1[i].substr(0,l)));
		pr[i]=add(out[u],q2[i].substr(r+1,(int)q1[i].size()-1-r)); 
		vis[pl[i]]=vis[pr[i]]=true;
	}
//	for(int i:rts) cerr<<i<<' ';cerr<<'\n';
	for(int i:rts) dfs(i);
	for(int i=1;i<=q;i++) if(q1[i].size()==q2[i].size()) 
		qrs[in[pl[i]]].push_back({in[pr[i]],i});
	for(int i=1;i<=n;i++) if(s1[i]!=s2[i]){
		int l=0,r=s1[i].size()-1;
		while(s1[i][l]==s2[i][l]) l++;
		while(s1[i][r]==s2[i][r]) r--;
		int u=find(1,s1[i].substr(l,r-l+1)+s2[i].substr(l,r-l+1));
		if(!u) continue;
		int ql=find(in[u],R(s1[i].substr(0,l)));
		int qr=find(out[u],s2[i].substr(r+1,(int)s1[i].size()-1-r)); 
		if(!ql||!qr) continue;
		ops[in[ql]].push_back({in[qr],1});
		ops[in[ql]].push_back({out[qr]+1,-1});
		ops[out[ql]+1].push_back({in[qr],-1});
		ops[out[ql]+1].push_back({out[qr]+1,1});
	}
	for(int i=1;i<=tot;i++){
		for(auto o:ops[i]) T.add(o[0],o[1]);
		for(auto o:qrs[i]) ans[o[1]]=T.ask(o[0]);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}

