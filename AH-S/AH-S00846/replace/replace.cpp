#include<bits/stdc++.h>
using namespace std;
const long long mod=563897568757247,base=53;
//字符串静态二维偏序
int trie[8000005][27];//维护s2
int cnt[8000005];
int ct=1;
void upd(string s,int r){
	// cerr<<"upd("<<s<<","<<r<<")\n";
	int u=1;
	for(int i=0;i<s.size();i++){
		if(!trie[u][s[i]^96]) trie[u][s[i]^96]=++ct;
		u=trie[u][s[i]^96];
	}
	cnt[u]+=r;
}
// int flag;
int qry(string s){
	// if(flag) exit(-1);
	int u=1;
	int res=cnt[u];
	// cerr<<"---\n";
	// if(flag)cerr<<"cnt["<<u<<"]="<<cnt[u]<<";\n";
	for(int i=0;i<s.size();i++){
		// if(flag)cerr<<"cnt["<<u<<"]="<<cnt[u]<<";\n";
		if(!trie[u][s[i]^96]) return res;
		if(u>trie[u][s[i]^96]) exit(1);
		u=trie[u][s[i]^96]; res+=cnt[u];
		// if(flag)cerr<<"cnt["<<u<<"]="<<cnt[u]<<";\n";
	}
	// cerr<<"res="<<res<<"\n";
	// if(flag) cerr<<res<<'\n';
	return res;
}
int n,q;
struct node{
	string s1,s2;
	int tp;//  1/2
	long long hs;
	int id;
};
node s[400005];
void solve(string &s1,string &s2,long long &hs,string u,string v){
	int l=0,r=u.size()-1;
	while(u[l]==v[l]) l++;
	while(u[r]==v[r]) r--;
	s1=u.substr(0,l); s2=u.substr(r+1,u.size());
	reverse(s1.begin(),s1.end());
	hs=0;
	for(int i=l;i<=r;i++){
		hs=(hs*base+u[i])%mod;
		hs=(hs*base+v[i])%mod;
	}
}
bool cmp(node x,node y){
	if(x.hs!=y.hs) return x.hs<y.hs;
	if(x.s1!=y.s1) return x.s1<y.s1;
	if(x.s2!=y.s2) return x.s2<y.s2;
	return x.tp<y.tp;
}
int cntt;
int st[400005],tp;//stack(is something in it)
int ans[200005];
bool check(string s,string t){
	if(s.size()<t.size()) return false;
	for(int i=0;i<t.size();i++){
		if(s[i]!=t[i]) return false;
	}
	return true;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	cin>>n>>q;
	cntt=0;
	for(int i=1;i<=n;i++){
		string u,v; cin>>u>>v; if(u!=v){
			cntt++;
			solve(s[cntt].s1,s[cntt].s2,s[cntt].hs,u,v);
			s[cntt].tp=1;
		}
	}
	for(int i=1;i<=q;i++){
		string u,v; cin>>u>>v; if(u!=v){
			cntt++;
			solve(s[cntt].s1,s[cntt].s2,s[cntt].hs,u,v);
			// if(i==27576) cerr<<s[cntt].hs<<'\n';
			s[cntt].tp=2;
			s[cntt].id=i;
		}
	}
	n=cntt;
	sort(s+1,s+1+n,cmp);
	// for(int i=1;i<=n;i++){
	// 	cerr<<s[i].s1<<'\t'<<s[i].s2<<'\t'<<s[i].hs<<'\t'<<s[i].tp<<'\t'<<s[i].id<<'\n';
	// }
	cntt=0;
	// exit(0);
	for(int i=1;i<=n;i++){
		// cerr<<i<<'\n';
		if(s[i].hs!=s[st[tp]].hs){
			while(tp){
				upd(s[st[tp]].s2,-1); tp--;
			}
		}
		while(!check(s[i].s1,s[st[tp]].s1)){
			upd(s[st[tp]].s2,-1); tp--;
		}
		// cerr<<"*\n";
		// if(s[i].id==27576){
		// 	for(int i=1;i<=tp;i++) cerr<<st[i]<<' '; cerr<<'\n';
		// }
		// if(s[i].hs==5836) cerr<<i<<'\n';
		if(s[i].tp==2){
			// if(s[i].id==27576) flag=1; else flag=0;
			ans[s[i].id]=qry(s[i].s2);
		}else{
			upd(s[i].s2,1); st[++tp]=i;
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<'\n';
	return 0;
}
