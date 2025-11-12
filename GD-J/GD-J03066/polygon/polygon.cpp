#include <iostream>
#include<algorithm>
using namespace std;
int n,a[510],f[510][50010],f1[50010],ans,MOD = 998244353;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		f[i][a[i]] = 1;
	}
	for(int i = 1;i < n;i++){
		for(int j = a[i]+1;j <= 50010;j++){
			f[i][j] = f1[j-a[i]];
		}
		for(int j = a[i];j <= 50010;j++){
			f1[j] = (f1[j]+f[i][j])%MOD;
			if(j > a[i+1]&&i >= 2){
				ans = (ans+f1[j])%MOD;
			}
		}	
	}
	cout << ans;
	return 0;
}
