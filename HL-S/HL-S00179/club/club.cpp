#include<bits/stdc++.h>
using namespace std;
int n;
int t;
int k;
int ans;
int e;
int r1 = 0,r2 = 0,r3 = 0;
struct people{
	int x, y, z;	
}p[10010];
int maxn(int m,int r,int q){
	int s = max(m,r);
	s = max(s,q);
	return s;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		k = n / 2;
		for(int i = 1;i <= n;i++){
			cin >> p[i].x >> p[i].y >> p[i].z;
		}
		for(int i = 1;i <= n;i++){
			int d = maxn(p[i].x,p[i].y,p[i].z);
			if(p[i].x == d and r1 < k){
				ans += p[i].x;
				r1 = r1 + 1;
				continue;
			} else if(p[i].x == d and r1 >= k){
				e = max(p[i].y,p[i].z);
				if(p[i].y == e and r2 < k){
					ans += p[i].y;
					r2 = r2 + 1;
					continue;
				}else{
					ans += p[i].z;
					r3 = r3 + 1;
					continue;
				}
			}
			if(p[i].y == d and r2 < k){
				ans += p[i].y;
				r2 = r2 + 1;
				continue;
			} else if(p[i].y == d and r2 >= k){
				e = max(p[i].x,p[i].z);
				if(p[i].x == e and r1 < k){
					ans += p[i].x;
					r1 = r1 + 1;
					continue;
				}else{
					ans += p[i].z;
					r3 = r3 + 1;
					continue;
				}
			}
			if(p[i].z == d and r3 < k){
				ans += p[i].z;
				r3 = r3 + 1;
				continue;
			}else if(p[i].z == d && r3 >= k)
				e = max(p[i].y,p[i].x);
				if(p[i].y == e and r2 < k){
					ans += p[i].y;
					r2 = r2 + 1;
					continue;
				}else{
					ans += p[i].x;
					r1 = r1 + 1;
					continue;
				}
			}
	cout << ans << endl;
	ans = 0;
	}
	return 0;
}