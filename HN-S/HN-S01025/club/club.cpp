#include<bits/stdc++.h>
using namespace std;
const int W = 1e5 + 5;
long long t, n, ans, num1, num2, num3, b[W], num4;
struct Node{
	int x, y, z, h;
}a[W];
bool qwq(Node xx, Node yy){
	return max(xx.x, max(xx.y, xx.z)) > max(yy.x, max(yy.y, yy.z));
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio, cin.tie(0), cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n;
		num1 = num2 = num3 = num4 = ans = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if((a[i].x >= a[i].y && a[i].x <= a[i].z) || (a[i].x >= a[i].z && a[i].x <= a[i].y)) a[i].h = max(a[i].y, a[i].z) - a[i].x;
			else if((a[i].y >= a[i].x && a[i].y <= a[i].z) || (a[i].y >= a[i].z && a[i].y <= a[i].x)) a[i].h = max(a[i].x, a[i].z) - a[i].y;
			else a[i].h = max(a[i].x, a[i].y) - a[i].z;
		}
		sort(a + 1, a + 1 + n, qwq);
		for(int i = 1; i <= n; i++){
			if(a[i].x >= a[i].y && a[i].x >= a[i].z){
				num1++;
				ans += a[i].x;
			}else if(a[i].y >= a[i].x && a[i].y >= a[i].z){
				num2++;
				ans += a[i].y; 
			}else{
				num3++;
				ans += a[i].z;
			}
		}
		if(num1 > n / 2){
			for(int i = 1; i <= n; i++){
				if(a[i].x >= a[i].y && a[i].x >= a[i].z) b[++num4] = a[i].h;
			}
		}else if(num2 > n / 2){
			for(int i = 1; i <= n; i++){
				if(a[i].y >= a[i].x && a[i].y >= a[i].z) b[++num4] = a[i].h;
			}
		}else{
			for(int i = 1; i <= n; i++){
				if(a[i].z >= a[i].x && a[i].z >= a[i].y) b[++num4] = a[i].h;
			}
		}
		sort(b + 1, b + 1 + num4);
		for(int i = 1; i <= max(num1, max(num2, num3)) - n / 2; i++){
			ans -= b[i];
		}
		cout << ans << '\n';
	}
	return 0;
}
