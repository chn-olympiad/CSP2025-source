#include<bits/stdc++.h>
#define endl '\n'
typedef long long ll;
using namespace std;

int n, m;
string s;
int c[505], cnt;
int p[505], b[505];
const int P = 998244353;

void dfs(int k){
	if(k > n){
		int q = 0;
		for(int i = 1; i <= n; i++){
			if(q >= c[p[i]] || s[i] == '0'){
				q++;
			}
		}
		if(n - q >= m) cnt++;
		return;		
	}
	for(int i = 1; i <= n; i++){
		if(!b[i]){
			b[i] = true, p[k] = i;
			dfs(k + 1);
			b[i] = false;
		}
	}
}

void work1(){
	for(int i = 1; i <= n; i++){
		if(s[i] == '0' || c[i] == 0){
			cout << 0 << endl;
			return;
		}
	}	
	int ans = 1;
	for(int i = 2; i <= n; i++){
		ans = 1ll * ans * i % P;
	}
	printf("%d\n", ans);
}

void work2(){
	cnt = 0;
	dfs(1);
	printf("%d\n", cnt);
}

int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	s = '#' + s;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
	}
	if(m == n) work1();
	else work2();
	return 0;
}
