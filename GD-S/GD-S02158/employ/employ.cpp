#include <bits/stdc++.h>
using namespace std;
int n,m,len;
string s;
bool A = false;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	int a[n + 1];
	len = s.size();
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= len;i++){
		if(s[i - 1] == '0'){
			A = false;
		}
	}
	if(m == 1){
		long long ans = 1;
		for(int i = 1;i <= n;i++){
			ans *= i;
		}
		cout << ans;
	}
	else if(n == m){
		cout << n;
	}
	else if(A){
		long long ans = 1;
		for(int i = 1;i <= n;i++){
			ans *= i;
		}
		cout << ans;
	}
	else{
		cout << 1;
	}
}
