#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 5;
int n , m;
string s;
int c[N];
int a[N];
int ans;
int mod = 998244353;
bool vis[N];
void slove(){
	int t = 0;
	int num = 0;
	for(int i = 1 ;i <= n ;i++){
		if(s[i] == '0'){
			t++;
			continue;
		}
		if(t >= c[a[i]]){
			t++;
		}else{
			num++;
		}
	}
	if(num >= m){
		ans++;
		ans %= mod;	
	}
}
void dfs(int x){
	if(x > n){
		slove();
	}
	for(int i = 1 ;i <= n ;i++){
		if(!vis[i]){
			vis[i] = 1;
			a[x] = i;
			dfs(x + 1);
			vis[i] = 0; 
		}
	}
	return ;
}
signed main(){
	freopen("employ.in" ,"r" , stdin);
	freopen("employ.out" , "w" , stdout); 
	cin >> n >> m;
	cin >> s;
	s = " " + s;  
	for(int i = 1 ;i <= n ;i++){
		cin >> c[i];		
	}
	dfs(1);
	cout << ans << endl;
	return 0;
} 
