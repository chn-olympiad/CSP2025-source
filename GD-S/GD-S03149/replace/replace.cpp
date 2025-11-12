#include<bits/stdc++.h>
#define int long long
#define For(i,x,y) for(int i = x;i <= y;i ++ )
#define For_(i,x,y) for(int i = x;i >= y;i --)
#define fs first
#define sc second
#define y0 y0_
#define y1 y1_
#define yn yn_
#define j0 j0_
#define j1 j1_
#define jn jn_
#define pii pair<int,int> 
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
const int mod = 998244353;
int n,q;
string s1[N],s2[N];
int nxt[N];
struct node{
	string T1,T2;
	int id;
}T[N];
vector<int> kmp(string s,string t){
	int n=s.size(),m=t.size();
	vector<int> ans;
	if(m > n) return ans;
	s=' '+s,t=' '+t;
	For(i,0,m) nxt[i] = 0;
	nxt[1] = 0;
//	cout << s << " " << t << " " << n << " " << m << endl;
	For(i,2,m){
		int j = nxt[i-1];
		while(j != 0 && t[j + 1] != t[i]) j = nxt[j];
		if(t[j + 1] == t[i]) nxt[i] = j + 1;
	}int j = 0;
//	For(i,1,m)cout << nxt[i] << " ";cout << endl; 
	For(i,1,n) {
		
		while(j != 0 && t[j + 1] != s[i]) j = nxt[j];
		if(t[j + 1] == s[i]) {
			++j;
			if(j == m){
				ans.pb(i-m+1);
				j = nxt[j];
			}	continue;
		}		
	}return ans;
}
bool chekstring(string s){
	int cnt = 0;
	for(auto it:s) if(it!='a' && it!='b') return false; else if(it=='b')cnt++;
	return cnt == 1;
} 
bool check(){
	int res = 1;
	For(i,1,n) res &= chekstring(s1[i]);
	For(i,1,n) res &= chekstring(s2[i]);
	For(i,1,q) res &= chekstring(T.T1[i]);
	For(i,1,q) res &= chekstring(T.T2[i]);
	return res;
} bool cmp(node a,node b) {
	return a.T1.size() < b.T1.size();
}
void specialA(){
	map<int,int> mp;
	vector<pii>add;
	For(i,1,n){
		int it1 = -1,it2 = -1;
		For(j,0,s1[i].size() - 1) if(s1[i][j] == 'b') it1 = j;
		For(j,0,s2[i].size() - 1) if(s2[i][j] == 'b') it2 = j;
		if(it2!=-1 && it1 != -1)add.pb({s1[i].size(),it2-it1));
	} sort(add.begin(),add.end());
	For(i,1,q) T.id=  i;
	sort(T+1,T+1+q,cmp);
	int It = 0;
	For(i,1,q){
		int it1 = 0,it2 = 0;
		if(T.T1[i].size() != T.T2[i].size()) {
			cout << 0 <<endl;continue;
		}
		
		while(It < add.size() && add[It].fs) mp[add[It++].sc] ++;
		
		
		
		For(j,0,T.T1[i].size() - 1) if(T.T1[i][j] == 'b') it1 = j;
		For(j,0,T.T2[i].size() - 1) if(T.T2[i][j] == 'b') it2 = j;
		
		cout << mp[it2-it1] << endl;
	} 
}
void solve(){
	cin >> n >> q;
	For(i,1,n) cin >> s1[i] >> s2[i];
	For(i,1,q){
		cin >> T.T1[i] >> T.T2[i];
	} 
	if(check()){
		specialA();
		return ;
	}
	
	For(k,1,q) {
		string t1,t2;
		t1 = T.T1[k],t2 = T.T2[k];
		if(t1.size() != t2.size()) {
			cout << 0 << endl;
			continue;
		}
		int ans = 0;
		int vf = -1e9,vb = 1e9;
		For(i,0,t1.size() - 1){
			if(t1[i] != t2[i]) break;
			vf = i;
		}For_(i,t1.size() - 1,0){
			if(t1[i] != t2[i]) break;
			vb = i;
		}
		For(i,1,n){
			vector<int> v1,v2;
//			cout << "KMP:" << t1 << " " << s1[i] << endl;
			v1 = kmp(t1,s1[i]);
//			cout << "KMP:" << t2 << " " << s2[i] << endl;
			v2 = kmp(t2,s2[i]);
			map<int,int> mp;
			for(auto it:v1) mp[it] = 1;
			for(auto it:v2) if(mp[it] == 1 && it-1 <= vf + 1 && it-1+s1[i].size() >= vb - 1) ans ++;
		}
		cout << ans << endl;
		
	}

//	string s,t;
//	cin >> s >> t;
//	vector<int> ans = kmp(s,t);
//	for(auto it : ans) cout << it << " " ;
	
} signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;
//	cin >> T;
	while(T--){
		solve();
	}return 0;
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
