#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 5;
struct node{
	int x, y, z, t;
}a[N];
bool cmp(node x, node y){
	return x.t > y.t;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out" ,"w", stdout);
	int T, n;
	cin >> T;
	while(T --){
		ll ans = 0;
		cin >> n;
		for(int i = 1;i <= n;i ++){
			scanf("%d %d %d", &a[i].x, &a[i].y, &a[i].z);
			if(a[i].x > a[i].y && a[i].x > a[i].z) a[i].t = a[i].x - max(a[i].y, a[i].z);
			if(a[i].y > a[i].x && a[i].y > a[i].z) a[i].t = a[i].y - max(a[i].x, a[i].z);
			if(a[i].z > a[i].x && a[i].z > a[i].y) a[i].t = a[i].z - max(a[i].x, a[i].y);
		}
		sort(a + 1, a + n + 1,cmp);
		int suma = 0, sumb = 0, sumc = 0, sua = 0, sub = 0, suc = 0;
		for(int i = 1;i <= n;i ++){
			if(a[i].x > a[i].y && a[i].x > a[i].z) sua ++;
			if(a[i].y > a[i].x && a[i].y > a[i].z) sub ++;
			if(a[i].z > a[i].x && a[i].z > a[i].y) suc ++;
		}
		for(int i = 1;i <= n;i ++){
			if(a[i].x > a[i].y && a[i].x > a[i].z){
				ans += a[i].x;
				if(suma < n / 2) suma ++;
				else ans -= a[i].t;
			}else if(a[i].y > a[i].x && a[i].y > a[i].z){
				ans += a[i].y;
				if(sumb < n / 2) sumb ++;
				else ans -= a[i].t;
			}else if(a[i].z > a[i].x && a[i].z > a[i].y){
				 ans += a[i].z;
				 if(sumc < n / 2) sumc ++;
				 else ans -= a[i].t;
			 }else if(a[i].x == a[i].y){
				 ans += a[i].x;
				 if(sua < sub) suma ++;
				 else sumb ++;
			 }else if(a[i].x == a[i].z){
				 ans += a[i].x;
				 if(sua < suc) suma ++;
				 else sumc ++;
			 }else {
				 ans += a[i].y;
				 if(sub < suc) sumb ++;
				 else sumc ++;
			 }
		}
		cout << ans << endl;
	}
	return 0;
}
