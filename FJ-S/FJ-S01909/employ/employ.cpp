#include<iostream>
using namespace std;
int mod = 998244353;
int n,m,c[505];
string s;
int main(){
	//freopen("employ1.in","r",stdin);
	//freopen("employ1.out","w",stdout);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >> s;
	for(int i = 1;i <= n;i++) cin >> c[i];
	int ans = 1;
	if(m == n){
		int cnt = 0;
		for(int i = 1;i <= n;i++) if(c[i] == 0) cnt++;
		if(cnt != 0){
			for(int i = 1;i <= n;i++) ans = (ans * i) % mod;
		}else ans = 0;
		cout << ans << endl;
		return 0;
	}
	cout << 0 <<endl;
	return 0;
}
