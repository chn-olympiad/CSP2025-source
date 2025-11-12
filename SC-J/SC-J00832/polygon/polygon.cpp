#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5001];
int vis[5001];
void xs(int i, int s, int b, int Max){
	if(i == b + 1){
		if(s > 2 * Max){
			ans++;
		}
		return;
	}
	for(int j = 1;j <= n;j++){
		if(vis[j] == 0){
			if(a[j] > Max ){
				Max = a[j];
			}
			vis[j] = 1;
			s += a[j];
			xs(i + 1, s, b, Max);
			s -= a[j];
			vis[j] = 0;
		}
		
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out","w", stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 3;i <= n;i++){
		xs(0, 0, i, -1);
	}
	cout << ans % 998244353;
	return 0;
}