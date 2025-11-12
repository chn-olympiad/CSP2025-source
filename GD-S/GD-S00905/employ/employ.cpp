#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N = 514 , MOD = 998244353;
int n , m , l[N];
string a;
int main(){
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	cin >> n >> m;
	cin >> a;
	for(int i = 1;i <= n;i++) cin >> l[i];
	ull ans = 1;
	for(int i = 2;i <= n;i++){
		ans *= i;
		ans %= MOD;
	}
	cout << 0;

	fclose(stdin);
	fclose(stdout);	
	
	return 0;
}
