#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int n,k,a[N],f[N],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	bool flag = false;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i] != 1)//如果不是特殊性质A 
			flag = true;
	}
	if(!k && !flag){//特殊性质A 
		if(!(n % 2))
			cout << n / 2;
		else
			cout << 0;
		return 0; 
	}
	if(k <= 1){//特殊性质B 
		for(int i = 1;i <= n;i++){
			if(a[i] == 1){
				vis[i] = 1;
				cnt++;
			}
		}
		for(int i = 1;i <= n;i++){
			if(vis[i] == 1)
				break;
			num++;
		}
		for(int i = n;i >= 1;i--){
			if(vis[i] == 1)
				break;
			num++;
		}
		if(!k){
			if(!(cnt % 2))
				cout << num + (cnt / 2);
			else
				cout << 0;
		}
		if(k){
			if(!(cnt % 2))
				cout << 0;
			else
				cout << cnt + num; 
		}
		return 0;
	}
	for(int i = 1;i <= n;i++){
		num ^= a[i];
		if(num == k){
			ans++;
			num = 0;
		}
	}
	if(num != 0)
		cout << 0 << endl;
	else
		cout << ans << endl;
	return 0;
} 
