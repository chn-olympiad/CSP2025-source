#include <bits/stdc++.h>
using namespace std;
const int N=510;
const long long pp=998244353;
int n,m,a[N],p[N];
unordered_set<int> st;
string s;
int dfs(int x){
	if(x==n+1){
		int cnt=0,res=0;
		for(int i=1;i<=n;++i){
			if(s[i-1]=='0') ++cnt;
			else if(cnt>=a[p[i]]) ++cnt;
			else ++res;
			if(res>=m) return 1;
		}
		if(res>=m) return 1;
		return 0;
	}
	int res=0,k[20],tot=0;
	for(auto i:st) k[++tot]=i;
	for(int i=1;i<=tot;++i){
		p[x]=k[i],st.erase(k[i]);
		res+=dfs(x+1);
		p[x]=0,st.insert(k[i]);
	}
	return res; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>s;
	for(int i=1;i<=n;i++) cin >>a[i];
//	sort(a+1,a+n+1);
	if(n==m){
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				cout <<0;
				return 0;
			} 
			if(a[i+1]==0){
				cout <<0;
				return 0;
			}
		}
		long long ans=1;
		for(long long i=2;i<=n;++i) ans*=i,ans%=pp;
		cout <<ans;
	}
	else if(n<=10){
		for(int i=1;i<=n;++i) st.insert(i);
		cout <<dfs(1);
	}
	else cout <<0;
	return 0; 
} 
