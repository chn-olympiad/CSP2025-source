#include<bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10 , mod =  998244353;
int n , m , a[N] , b[N];
bool f = true;

int main(){

	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 1;i <= n;i ++){
		a[i] = s[i-1]-'0';
		cin >> b[i];
		if(a[i] == 0)	f = false;
	}
	if(f){
		long long res = 1;
		for(int i = 1;i <= m;i ++){
			res *= i;
			res%=mod;
		}
		cout << res;
	}
	else cout << 0;
	return 0;
}

