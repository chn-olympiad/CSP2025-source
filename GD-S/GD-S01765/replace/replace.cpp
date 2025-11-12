#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
using namespace std;
const int N = 5000100;
const int base = 37;
const int mod = 998244353;
int n,q;
int ph[N];
ull ps[N];
string st;
string s1[N],s2[N];
string t1[N],t2[N];
vector <int> hs1[N],hs2[N],ht1[N],ht2[N];
vector <ull> ss1[N],ss2[N],st1[N],st2[N];
inline void inits1(int x){
	int len=st.size()-1;
	hs1[x].push_back(0);
	ss1[x].push_back(0);
	for(int i=1;i<=len;i++){
		hs1[x].push_back((hs1[x][i-1]*base%mod+st[i]-'a'+1)%mod);
		ss1[x].push_back((ss1[x][i-1]*base+(ull)(st[i]-'a'+1)));
	}
	return;
}
inline void inits2(int x){
	int len=st.size()-1;
	hs2[x].push_back(0);
	ss2[x].push_back(0);
	for(int i=1;i<=len;i++){
		hs2[x].push_back((hs2[x][i-1]*base%mod+st[i]-'a'+1)%mod);
		ss2[x].push_back((ss2[x][i-1]*base+(ull)(st[i]-'a'+1)));
	}
	return;
}
inline void initt1(int x){
	int len=st.size()-1;
	ht1[x].push_back(0);
	st1[x].push_back(0);
	for(int i=1;i<=len;i++){
		ht1[x].push_back((ht1[x][i-1]*base%mod+st[i]-'a'+1)%mod);
		st1[x].push_back((st1[x][i-1]*base+(ull)(st[i]-'a'+1)));
	}
	return;
}
inline void initt2(int x){
	int len=st.size()-1;
	ht2[x].push_back(0);
	st2[x].push_back(0);
	for(int i=1;i<=len;i++){
		ht2[x].push_back((ht2[x][i-1]*base%mod+st[i]-'a'+1)%mod);
		st2[x].push_back((st2[x][i-1]*base+(ull)(st[i]-'a'+1)));
	}
	return;
}
bool checkt(int u,int l1,int r1,int v,int l2,int r2){
	if((((ht1[u][r1]-ht1[u][l1-1]*ph[r1-l1+1]%mod)%mod+mod)%mod)!=(((ht2[v][r2]-ht2[v][l2-1]*ph[r2-l2+1]%mod)%mod+mod)%mod)) return false;
	if((st1[u][r1]-st1[u][l1-1]*ps[r1-l1+1])!=(st2[v][r2]-st2[v][l2-1]*ps[r2-l2+1])) return false;
	return true;
}
bool checkst(int u,int l1,int r1,int v,int l2,int r2){
	if((((hs1[u][r1]-hs1[u][l1-1]*ph[r1-l1+1]%mod)%mod+mod)%mod)!=(((ht1[v][r2]-ht1[v][l2-1]*ph[r2-l2+1]%mod)%mod+mod)%mod)) return false;
	if((ss1[u][r1]-ss1[u][l1-1]*ps[r1-l1+1])!=(st1[v][r2]-st1[v][l2-1]*ps[r2-l2+1])) return false;
	if((((hs2[u][r1]-hs2[u][l1-1]*ph[r1-l1+1]%mod)%mod+mod)%mod)!=(((ht2[v][r2]-ht2[v][l2-1]*ph[r2-l2+1]%mod)%mod+mod)%mod)) return false;
	if((ss2[u][r1]-ss2[u][l1-1]*ps[r1-l1+1])!=(st2[v][r2]-st2[v][l2-1]*ps[r2-l2+1])) return false;
	return true;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	ph[0]=1; ps[0]=1;
//	cout<<0<<'\n';
	for(int i=1;i<N;i++) ph[i]=ph[i-1]*base%mod;
	for(int i=1;i<N;i++) ps[i]=ps[i-1]*base;
	cin>>n>>q;
//	cout<<1<<'\n';
	for(int i=1;i<=n;i++){
		cin>>st;
		st=" "+st; s1[i]=st;
		inits1(i);
		cin>>st;
		st=" "+st; s2[i]=st;
		inits2(i);
	}
//	cout<<2<<'\n';
	for(int i=1;i<=q;i++){
		int l1,l2;
		cin>>st;
		st=" "+st; t1[i]=st;
		l1=st.size();
		initt1(i);
		cin>>st;
		st=" "+st; t2[i]=st;
		l2=st.size();
		initt2(i);
		if(l1!=l2){
			cout<<0<<'\n';
			continue;
		}
		int m=st.size()-1;
		int l=0,r=m+1;
		while(l<m && checkt(i,1,l+1,i,1,l+1)) l++;
		while(r>1 && checkt(i,r-1,m,i,r-1,m)) r--;
		int res=0;
		for(int j=1;j<=n;j++){
			int len=s1[j].size()-1;
			for(int k=max(1ll,r-len);k<=l+1 && k+len-1<=m;k++){
				res+=checkst(j,1,len,i,k,k+len-1); 
			}
		}
		cout<<res<<'\n';
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

*/
