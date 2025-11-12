#include <bits/stdc++.h>
using namespace std;
int ixor(int x , int y){
	int n = 1;
	int sum = 0;
	while(max(x , y)){
		sum += ((x % 2) != (y % 2))*n;
		n *= 2;
		x /= 2,y /= 2; 
	}
	return sum;
}
int a[5005] , b[5005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n , k;
	cin >> n >> k;
	cin >> a[1];
	for(int i = 2;i <= n;i++){
		cin >> a[i];
		b[i - 1] = ixor(a[i] , a[i - 1]);
	}
	int ans = 0;
	int l = n + 1 , r = 0;
	bool flag = true;
	for(int i = 1;i <= n;i++){
		if(k == a[i] && i >= r){
			ans++;
			r = max(r , i);
			flag = false;
		}else if(i != n && k == b[i] && i >= r){
			r = max(r , i + 1);
			flag = false;
		}
		for(int j = i + 2;j <= n;j++){
			int x = ixor(b[i],a[j]);
			if(x == k){
				ans++;
				r = max(r , j);
				break;
			}
			for(int t = j + 1;t <= n;t++){
				if(j <= r)
					break;
				int y = ixor(x , a[t]);
				if(y == k){
					ans++;
					r = max(r , k);
					break;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
