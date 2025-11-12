#include<bits/stdc++.h>
using namespace std;
const int mod  = 998244353;
int c[505];
bool vis[100];
int a[100];
queue<int> q;
void dfs(int step){
	if(step == 5) {
		for(int i = 1;i <= 4;i ++ ) {
			cout <<a[i]<<" ";
		}
		cout<<endl; 
	}
	for(int i = 1;i <= 4;i ++){
		if(vis[i]==0){
			a[step] = i;
			vis[i]=1;
			dfs(step + 1);
			vis[i] = 0;
		}
	}
	return ;
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
//	for(int i = 1 ; i <= 6; i ++ ) a[i] =i;
	dfs(1);
//	int n, m;
//	string s;
//	cin >> n >> m >> s;
//	for(int i = 1 ; i <= n; i ++ ) cin >> c[i];
//	bool flag = 1;
//	
//	
//	for(int i = 0; i < n; i ++ ){
//		if(s[i] == '0'){	
//			flag = 0;
//			break;
//		}
//	}
//	if(flag){
//		long long sum = 1;
//		for(int i = n; i >= n - m + 1; i -- ){
//			sum *= i;
//			sum %= mod;
//		}
//		cout << sum;
//	}
//	else{
//		dfs(,);
//	}
	return 0;
} 
