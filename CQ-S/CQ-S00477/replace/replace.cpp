#include<bits/stdc++.h>
#define N 812345
using namespace std ;
int n , q , cnt=0 , t[N] , dfs[N] , sz[N] , son[N] , tr[N][30] , tot=0 , top[N] , dep[N] , fa[N] , cl , sam1[N] , sam2[N] , hd[N] , order[N][26] , others=0 , tl[N] ;
string s1[N] , s2[N] ;
vector<int> e[N] , root[N] ;
void add(int &x,char a,int number){
	if(!tr[x][a-'a']) tr[x][a-'a'] = ++cnt ;
	x = tr[x][a-'a'] ;
}
void bu(int &x,char a,int number){
	if(!order[x][a-'a']) order[x][a-'a'] = ++others ;
	x = order[x][a-'a'] ;
}
int ask(vector<int> &rt,int L,int R){
	int l=0 , r=rt.size()-1 , ansl=r , ansr=r-1 ;
	if(l>r) return 0 ;
//	cout  << "st\n" ;
	while(l<=r){
		int mid=(l+r)>>1 ;
		if(rt[mid]>=L) r = mid-1 , ansl = mid ;
		else l = mid+1 ;
	}
	while(l<=r){
		int mid=(l+r)>>1 ;
		if(rt[mid]<=R) l = mid+1 , ansr = mid ;
		else r = mid-1 ;
	}
//	cout << "ed\n" ;
//	cout << rt[0]<< endl ;
//	cout << ansr << " " << ansl << endl ;
	return ansr-ansl+1 ;
}
void dfs1(int u,int f){
	dep[u] = dep[f]+1 ;
	sz[u] = 1 ;
	fa[u] = f ;
	for(int i=0;i<26;i++){
		if(!order[u][i]) continue ;
		int x=order[u][i] ;
		dfs1(x,u) ;
		sz[u] += sz[x] ;
		if(!son[u]||sz[son[u]]<sz[x]) son[u] = x ;
	}
}
void dfs2(int u,int head){
	top[u] = head ;
	dfs[u] = ++tot ;
	if(son[u]) dfs2(son[u],head) ;
//	cout << u << " " << head << " " << son[u] << endl ;
	for(int i=0;i<26;i++){
		if(!order[u][i]||order[u][i]==son[u]) continue ;
		int x=order[u][i] ;
		dfs2(x,x) ;
	}
}
void getval(int u){
	for(int i=0,z=root[u].size();i<z;i++) root[u][i] = dfs[tl[root[u][i]]] ;
	sort(root[u].begin(),root[u].end()) ;
	for(int i=0;i<26;i++){
		if(!tr[u][i]) continue ;
		getval(tr[u][i]) ;
	}
}
unordered_map<string,unordered_map<string,int>> mp ;
int find(int u,string &s,int dep,int L,int R){
	if(!u||dep==s.size()) return 0 ;
	return ask(root[u],L,R)+find(tr[u][s[dep]-'a'],s,dep+1,L,R) ;
}
int LCA(int x,int y,int u,string &s){
	int ans=0 ;
	while(top[x]!=top[y]){
		if(dep[top[x]]>dep[top[y]]) swap(x,y) ;
//		cout << dfs[top[x]] << " " << dfs[x] << endl ;
		ans += find(u,s,0,dfs[top[x]],dfs[x]) ;
		x = fa[top[x]] ;
	}
	if(dep[x]<dep[y]) swap(x,y) ;
	ans += find(u,s,0,dfs[x],dfs[y]) ;
	return ans ;
}
signed main(){
	freopen("replace.in","r",stdin) ;
	freopen("replace.out","w",stdout) ; 
	cin >> n >> q ;
	for(int i=1;i<=n;i++) cin >> s1[i] >> s2[i] ;
	for(int i=1;i<=n;i++){
		if(s1[i]==s2[i]) continue ;
		int l=0 , r=s1[i].size()-1 ;
		while(s1[i][l]==s2[i][l]) l++ ;
		while(s1[i][r]==s2[i][r]) r-- ;
		string temp1 , temp2 ;
		for(int j=l;j<=r;j++) temp1 += s1[i][j] ,  temp2 += s2[i][j] ;
		if(!mp[temp1][temp2]) mp[temp1][temp2] = ++cl ;
		sam1[i] = l-1 , sam2[i] = r+1 ;
		e[mp[temp1][temp2]].push_back(i) ;
	}
	
	for(int i=1;i<=cl;i++){
//		cout << "now:" << i << endl ;
		hd[i] = ++cnt ;
		for(auto x:e[i]){
			if(sam1[x]==-1) root[hd[i]].push_back(x) ;
			int now=hd[i] ;
			for(int i=sam1[x];~i;i--) add(now,s1[x][i],x) ;
			root[now].push_back(x) ;
		}
		t[i] = ++others ;
		for(auto x:e[i]){
			int now=t[i] ;
			for(int i=sam2[x],z=s1[x].size();i<=z;i++) bu(now,s1[x][i],x)/* , cout << now << " " << s1[x][i] << endl*/ ;
			tl[x] = now ;
		}
		tot=0 ;
//		cout << "DONE!\n" ;
		dfs1(t[i],0) ;
		dfs2(t[i],t[i]) ;
		getval(hd[i]) ;
	}
//	cout << "PASS!!!!!!!\n" ;
	for(int i=1;i<=q;i++){
		string t1 , t2 ;
		cin >> t1 >> t2 ;
		int l=0 , r=t1.size() ;
		while(t1[l]==t2[l]) l++ ;
		while(t1[r]==t2[r]) r-- ;
		string temp1 , temp2 ;
		for(int i=l;i<=r;i++) temp1 += t1[i] , temp2 += t2[i] ;
		if(!mp[temp1][temp2]){
			puts("0") ;
			continue ;
		}
		int wei=mp[temp1][temp2] ;
		temp1.clear() , temp2.clear() ;
		for(int i=l-1;~i;i--) temp1 += t1[i] ;
		for(int i=r+1,z=t1.size();i<z;i++) temp2 += t2[i] ;
		int sz2=temp2.size() , now=t[wei] ;
		for(int i=0;i<sz2;i++) if(!order[now][temp2[i]-'a']) break ;else now = order[now][temp2[i]-'a'] ;
//		cout << now << " " << t[wei] << endl ;
		if(now==hd[wei]) printf("%d\n",find(hd[wei],temp1,0,1,n)) ;
		else printf("%d\n",LCA(now,t[wei],hd[wei],temp1)) ;
	}
	return 0 ;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
