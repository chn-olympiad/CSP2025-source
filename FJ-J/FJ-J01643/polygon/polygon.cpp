#include<bits/stdc++.h>
using namespace std;
const int N = 30;
const int mod = 998244353;
int n, arr[N];
int ans = 0, Vis[N];
bool type_all1 = true;

int read(){
	int x = 0, y = 1;
	char ch = getchar();
	while(ch < '0'|| ch > '9'){
		if( ch == '-') y = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * y;
}

bool check(){
	int Max = 0, tot = 0;
	for(int i = 1; i <= n; i++){
		if(Vis[i]){
			Max = max(Max, arr[i]);
			tot += arr[i]; 
		}
	}
	if(tot > 2 * Max) return true;
	return false;
}

void dfs(int pos){
	if(pos > n){
		if(check()){
			ans = (ans + 1) % mod;
//			for(int i = 1; i <= n; i++){
//				if(Vis[i]) cout << arr[i] << " "; 
//			} 
//			cout << endl;
		}
		return ;
	}
	Vis[pos] = 1;
	dfs(pos + 1);
	Vis[pos] = 0;
	dfs(pos + 1);
	return ;
}

int A(int a, int b){
	int c = 1;
	for(int i = 1; i <= a; i++){
		c *= b;
		b--;
	}
	return c;
}

int AA[N], BB[N]; 

int C(int a, int b){
	return (AA[a] / BB[a]) % mod;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	cout << C(4, 5) <<endl;
//	cout <<A(4, 5) << "£º" <<A(4, 4) <<endl; 
	n = read();
	for(int i = 1; i <= n; i++){
		arr[i] = read();
		if(arr[i] != 1) type_all1 = false;
//		cout << arr[i] << " ";
	} 
//	cout << "---------" <<endl;
	if(type_all1){
//		ans = count();
//		cout << ans << endl;
//		cout << 1 << endl;
		AA[0] = BB[0] = 1;
		for(int i = 1; i <= n; i++){
			AA[i] = 1;
			BB[i] = 1;
			AA[i] = AA[i - 1] * (n - i + 1);
			BB[i] = BB[i - 1] * i;
//			cout << AA[i]  << " " << BB[i] << endl;
		}

		for(int i = n; i >= 3; i--){
			ans = (ans + C(i, n)) % mod;
		}
		cout << ans <<endl;
		return 0;
	}
	dfs(1);
	cout << ans << endl;
	return 0; 
}
