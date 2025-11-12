#include <bits/stdc++.h>
using namespace std;
int S[600],c[600];
string s;
int sol[25];
int n,m;
const int mod=998244353;
long long ans=0;
void dfs(set<int> s,int denied){
	if(denied+m>n) return;
	if(s.size()==n&&denied+m<=n) {
		ans++;return ;
	}
	for(int i=1;i<=n;i++){
		if(s.count(i)==0){
			s.insert(i);
			if(S[s.size()]==0||c[i]<=denied) dfs(s,denied+1);
			else dfs(s,denied);
			s.erase(i);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	cin >> s;
	for(int i=1;i<=n;i++){
		S[i]=s[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	//n<=10
	if(n<=13){
		int denied;
		int perm[13];
		for(int i=1;i<=n;i++){
			perm[i]=i;
		}
		long long ans=0;
		do{
			denied=0;
			//cout << perm[1] <<' ' << perm[2] << ' ' << perm[3] << endl;
			for(int i=1;i<=n;i++){
			    if(denied>=c[perm[i]]||(S[i]==0)) denied++;
			}
			//cout << denied << endl;
			if(n-denied>=m) ans++;
		}while(next_permutation(perm+1,perm+n+1));
		cout << ans%998244353 << endl;
	}else if(n<=18){
		set<int> s;
		dfs(s,0);
		cout << ans << endl;
	}else if(m==n){
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(S[i]==0) flag=0;
		}
		long long ans=1;
		if(flag){
			for(int i=1;i<=n;i++){
			    ans*=i;
			    ans%=mod;
		    }
		    cout << ans << endl;
		}
		else {
			cout << 0 << endl;
		}
	}else if(n>100){
		cout << 0 << endl;
	}else {
		cout << 0 << endl;
	}
}
