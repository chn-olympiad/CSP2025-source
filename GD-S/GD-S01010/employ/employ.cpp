#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
const int mod = 998244353;
int n,m,sum;
string s;
int a[N];
int b[N];
int c[N];
int d[N];
bool vis[N];
void dfs(int x, int y, int z){
	if(x == n + 1){
		if(z >= m){
			sum++;
/*			cout << y << ' ' << z << endl;
			for(int i = 1; i <= n; i++){
				cout << b[i] << ' ';
			}
			cout << endl;//*/
		} 
		return;
	}
	for(int i = 1; i <= n; i++){
		if(vis[i] == false){
			vis[i] = true;
			b[x] = i;
			if(y >= a[i] || s[x - 1] == '0'){
				dfs(x + 1, y + 1, z);
			} else{
				dfs(x + 1, y, z + 1);
			}
			vis[i] = false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin >> s;
	for(int i = 1; i <= n; i++){
		scanf("%lld",&a[i]);
	}
	sort(a + 1, a + 1 + n);
	bool flag = false;
	for(int i = 1; i <= s.size(); i++){
		if(s[i - 1] == '0'){
			flag = true;
			break;
		}
	}
	if(flag == false){
		int t = 0;
		for(int i = 1; i <= n; i++){
			if(a[i] != 0){
				t++;
			}
		}
		int t1 = 1;
		for(int i = 1; i <= t; i++){
			t1 = t1 * i;
			t1 = t1 % mod;
		}
		printf("%lld",t1);
		return 0;
	}
	if(m == n){
		if(flag == true){
			printf("0");
		}
		return 0;
	}
	dfs(1,0,0);
	printf("%lld",sum);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
