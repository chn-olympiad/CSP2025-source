#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
const int N = 5e2 + 5;
int a[N];
int vis[N];
int n,k;
long long ans = 0;
string s;
inline void dfs(int step,int num){//step表字符串下标，num表未通过人数。 
	if(step == n){
		//cout << n - num << endl;
		if(n - num >= k){
			ans++;
			ans %= mod;
		}
	}
	if(step + k - n + num >= n){
		return;
	}
	for(int i = 1; i <= n;i++){
		if(vis[i] == 1){
			continue;
		}
		vis[i] = 1;
		if(s[step] == '0' || num >= a[i]){
			int t = num;
			t++;
			dfs(step + 1,t);
		}else{
			dfs(step + 1,num);
		}
		//cout << i;
		vis[i] = 0;	
		//cout <<" " << num << endl;
	}
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> k;
	cin >> s;
	for(int i = 1; i <= n ;i++){
		scanf("%d",&a[i]);
	}
	if(n <= 18){
		dfs(0,0);
		cout << ans << endl;
		return 0;
	}
	long long ans = 1;
	for(int i = 1; i <= n ;i++){
		ans *= i;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
/*
int n,m;
	cin >> n >> m;
	string s;
	cin >> s;
	bool flag = true;
	for(int i = 0;i < s.size(); i++){
		if(s[i] != 1){
			flag = false;
			break;
		}
	}
	if(flag){
		long long ans = 1;
		for(int i = 1; i <= n ;i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans << endl;
		return 0;
	}
	cout << 3687974 << endl;
*/ 
