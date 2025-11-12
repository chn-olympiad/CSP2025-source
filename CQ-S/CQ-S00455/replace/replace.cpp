#include<bits/stdc++.h>
#define N 200005
#define M 5000005
#define mod1 1000000007
#define mod2 1000000009
using namespace std;
struct node{int x,y,z;}que[N<<1];
inline bool cmp(node a,node b){
	if(a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}
vector<int> hs[M];
vector<pair<int,int> > hs2[M];
int n,q,i,j,k,l,tot,ans[N],bel[N],isd[N],trie[M][26],fail[M],la[M],ne[M],to[M],et,tots,quee[M],head,tail,cnt[M];
string s[N][2],t[N][2];
inline void merge(int x,int y){et++,ne[et]=la[x],la[x]=et,to[et]=y;}
inline void ins(string s,int val){
	int p = 0;
	for(int i=0;i<s.size();i++){
		if(!trie[p][s[i]-'a']) trie[p][s[i]-'a']=++tots;
		p = trie[p][s[i]-'a'];
	}
	if(val!=-1) hs[p].push_back(val);
}
inline void build(){
	head=1,tail=0;
	for(int i=0;i<26;i++) if(trie[0][i]) quee[++tail]=trie[0][i];
	while(head<=tail){
		int tmp = quee[head++];
		for(int i=0;i<26;i++){
			if(trie[tmp][i]){
				fail[trie[tmp][i]] = trie[fail[tmp]][i];
				quee[++tail] = trie[tmp][i];
			}
			else trie[tmp][i] = trie[fail[tmp]][i];
		}
	}
	for(int i=1;i<=tots;i++) merge(fail[i],i);
}
inline void dfs(int x){
	for(int i=0;i<hs[x].size();i++) cnt[hs[x][i]]++;
	for(int i=0;i<hs2[x].size();i++) ans[hs2[x][i].second]+=cnt[hs2[x][i].first];
	for(int i=la[x];i;i=ne[i]) dfs(i);
	for(int i=0;i<hs[x].size();i++) cnt[hs[x][i]]--;
}
inline void clear(){
	for(int i=0;i<=tots;i++){
		hs[i].clear(),hs2[i].clear();
		la[i]=0,quee[i]=0,fail[i]=0;
		for(int j=0;j<26;j++) trie[i][j]=0;
	}
	for(int i=1;i<=et;i++) ne[i]=0,to[i]=0;
	et=0,tots=0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>s[i][0]>>s[i][1];
	for(i=1;i<=q;i++) cin>>t[i][0]>>t[i][1];
	for(i=1;i<=n;i++){
		if(s[i][0]==s[i][1]) continue;
		int p1 = -1,p2 = -1,h1 = 0,h2 = 0;
		for(j=0;j<s[i][0].size();j++){
			if(s[i][0][j]!=s[i][1][j]){
				if(p1==-1) p1=j;
				p2=j;
			}
		}
		for(j=p1;j<=p2;j++) h1=(1ll*h1*13331+s[i][0][j])%mod1,h2=(1ll*h2*13331+s[i][1][j])%mod2;
		que[++tot] = (node){h1,h2,i},bel[i] = s[i][0].size()-1-p2;
	}
	for(i=1;i<=q;i++){
		if(t[i][0].size()!=t[i][1].size()) continue;
		int p1 = -1,p2 = -1,h1 = 0,h2 = 0;
		for(j=0;j<t[i][0].size();j++){
			if(t[i][0][j]!=t[i][1][j]){
				if(p1==-1) p1=j;
				p2=j;
			}
		}
		for(j=p1;j<=p2;j++) h1=(1ll*h1*13331+t[i][0][j])%mod1,h2=(1ll*h2*13331+t[i][1][j])%mod2;
		isd[i] = p2;
		que[++tot] = (node){h1,h2,-i};
	}
	sort(que+1,que+tot+1,cmp);
	for(i=1;i<=tot;i=j){
		for(j=i;j<=tot;j++) if(que[i].x!=que[j].x||que[i].y!=que[j].y) break;
		int l=i,r=j-1,c0=0,c1=0;
		for(k=l;k<=r;k++){
			if(que[k].z>0) c0++;
			else c1++;
		}
		if(c0==0||c1==0) continue;
		for(k=l;k<=r;k++){
			if(que[k].z>0) ins(s[que[k].z][0],bel[que[k].z]);
			else ins(t[-que[k].z][0],-1);
		}
		build();
		for(k=l;k<=r;k++){
			if(que[k].z>0) continue;
			int id = -que[k].z,p = 0;
			for(l=0;l<t[id][0].size();l++){
				p = trie[p][t[id][0][l]-'a'];
				if(l>=isd[id]) hs2[p].push_back(make_pair(l-isd[id],id));
			}
		}
		dfs(0);
		clear();
	}
	for(i=1;i<=q;i++) cout<<ans[i]<<"\n";
	return 0;
}
