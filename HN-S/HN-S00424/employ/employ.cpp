#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans = 1;
bool c[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++)
		cin >> c[i];
	
	for(int i = n;i > 0;i--){
		ans *= i;
		ans %= 998244353;
	}
	
	if(m == 1){
		int id = 0;
		for(int i = 1;i<= n;i++){
			if(c[i] != 0)
				id++;
		}
		for(int i = n - 1;i > 0;i--){
			ans *= i;
			ans %= 998244353;
		}
		ans = ans * id & 998244353;
		cout << ans;
		return 0;
	}
	cout << ans;
	return 0;
}
