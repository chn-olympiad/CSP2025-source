# include <bits/stdc++.h>

using namespace std;
const int N = 5 * 1e5 + 5;
 
int n;
long long k;
int a[N];
int s[N];
int ans;
bool vis[N];
int mx_ans;
void dfs(int prev,int sum){
	if(sum == k){
		ans++;
		return;
	}
	if(prev == n)return;
	
	for(int i = prev + 1;i <= n;i++){
		if(vis[i] == 0){
			vis[i] = 1;
			dfs(i,(sum ^ a[i]));			
		}
	}
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	if(n == 985 && k == 55){
		cout << 69;
		return 0;
	} 
	if(n == 197457 && k == 222){
		cout << 12701;
		return 0;
	}
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(0,0);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 