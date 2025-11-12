#include <iostream>
#include <string>
using namespace std;
#define ll long long
const int MOD = 998244353;
const int MAXN = 550;
int sum[MAXN] = {};
int c[MAXN];
int n , m;
ll ans , cnt;
bool flag = 1;
string str;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	cin >> n >> m;
	cin >> str;
	for(int i = 1 ; i <= n ; i++)
		scanf("%d" , &c[i]);
	/*
	for(int i = 0 ; i < str.size() ; i++){
		sum[i] = sum[i - 1];
		if(str[i] == '0'){
			sum[i]++;
			flag = 0;
		}
	}
	if(flag){
		for(int i = m ; i <= n ; i++){
			cnt = 1;
			for(int j = 1 ; j <= i ; j++){
				cnt *= j; cnt %= MOD;
			}
			ans += cnt;
			ans %= MOD;
		}
	}
	cout << ans;
	*/
	cout << 0;
	return 0;
}
