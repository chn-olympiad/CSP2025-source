#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
inline void read(int &x){
	x = 0;
	bool f = 0;
	char c = getchar();
	while(c < '0' || c > '9'){
		f = (c == '-');
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = (x << 3) + (x << 1) + (c & 15);
		c = getchar();
	}
	if(f) x = -x;
}
struct node{
	int x , y , z;
}a[N] , h[N];
inline bool cmd(node a , node b){
	return min(a.x , a.y) < min(b.x , b.y);
}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	int t;
	cin >> t;
	while(t --){
		int n;
		cin >> n;
		for(int i = 1;i <= n;++ i)
		read(a[i].x) , read(a[i].y) , read(a[i].z);
		int t1 , t2 , t3;
		t1 = t2 = t3 = 0;
		int ans = 0;
		for(int i = 1;i <= n;++ i){
			int s = max(max(a[i].x , a[i].y) , a[i].z);
			ans += s;
			if(s == a[i].x){
				h[i].x = s - a[i].y;
				h[i].y = s - a[i].z;
				h[i].z = 1;
				++ t1;
			}
			else if(s == a[i].y){
				h[i].x = s - a[i].x;
				h[i].y = s - a[i].z;
				h[i].z = 2;
				++ t2;
			}
			else{
				h[i].x = s - a[i].x;
				h[i].y = s - a[i].y;
				h[i].z = 3;
				++ t3;
			}
		}
		sort(h + 1 , h + 1 + n , cmd);
		if(t1 > (n >> 1)){
			for(int i = 1;i <= n;++ i){
				if(h[i].z == 1){
					ans -= min(h[i].x , h[i].y);
					-- t1;
					if(t1 <= (n >> 1)) break;
				}
			}
		}
		else if(t2 > (n >> 1)){
			for(int i = 1;i <= n;++ i){
				if(h[i].z == 2){
					ans -= min(h[i].x , h[i].y);
					-- t2;
					if(t2 <= (n >> 1)) break;
				}
			}
		}
		else if(t3 > (n >> 1)){
			for(int i = 1;i <= n;++ i){
				if(h[i].z == 3){
					ans -= min(h[i].x , h[i].y);
					-- t3;
					if(t3 <= (n >> 1)) break;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}