#include<bits/stdc++.h>
using namespace std;
struct Ser{
	int x, y;
};
Ser d[500005];
int vis[500005];
int a[500005], b[260];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n, k;
	cin >> n >> k;
	bool flag = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		b[a[i]]++;
		if(a[i] != 1){
			flag = 0;
		}
	}
	if(flag){
		cout << n / 2;
		return 0;
	}
	if(k == 0){
		cout << b[1]/2+b[0]/2;
		return 0;
	}
	if(k == 1){
		cout << b[1];
		return 0;
	}
	int u = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n-i; j++){
			int sum = 0;
			for(int r = j; r < j+i; r++){
				sum ^= a[r];
			}
			if(sum == k){
				d[u].x = j;
				d[u].y = j+i;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= u; i++){
		bool f = 0;
		int r = 0;
		for(int j = d[u].x; j <= d[u].y; j++){
			if(vis[j] == 1){
				f = 1;
				r = j;
				break;
			}
			vis[i] = 1;
		}
		if(f){
			for(int j = d[u].x; j <= r; j++){
				vis[j] = 1;
			}	
		}else{
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
