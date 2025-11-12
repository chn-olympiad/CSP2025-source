#include <bits/stdc++.h>
using namespace std;
struct bm{
	int x1,x2,x3;
}a[100005];
bool cmp(bm x,bm y){
	return x.x1 > y.x1; 
}
int main(){
//	¼ÇµÃÈ¥×¢ÊÍ 
//	freopen ("club.in","r",stdin);
//	freopen ("club.out","w",stdout);
	int n,t;
	cin >> t;
	for (int i = 1; i <= t; i++){
		int cnt = 0,m1 = 0,m2 = 0,m3 = 0;
		cin >> n;
		for (int j = 1; j <= n; j++){
			cin >> a[j].x1 >> a[j].x2 >> a[j].x3; 
		}
		if (n == 2){
			if (a[1].x1 > a[1].x2 && a[1].x1 > a[1].x3){
				cnt += a[1].x1; 
				m1++;
			}else if (a[1].x2 > a[1].x3 && a[1].x2 > a[1].x1){
				cnt += a[1].x2;
				m2++;
			}else if (a[1].x3 > a[1].x2 && a[1].x3 > a[1].x1){
				cnt += a[1].x3;
				m3++;
			}
			if (a[2].x1 > a[2].x2 && a[2].x1 > a[2].x3){
				if (m1 == 0) cnt += a[2].x1; 
				else cnt += max(a[2].x2,a[2].x3);
			}else if (a[2].x2 > a[2].x3 && a[2].x2 > a[2].x1 ){
				if (m2 == 0) cnt += a[2].x2; 
				else cnt += max(a[2].x1,a[2].x3);
			}else if (a[2].x3 > a[2].x2 && a[2].x3 > a[2].x1){
				if (m3 == 0) cnt += a[2].x3;
				else cnt += max(a[2].x2,a[2].x1);
			}
			cout << cnt;
			return 0;
		}else{
			sort(a + 1,a + n + 1,cmp);
			for (int j = 1; j <= n / 2; j++){
				cnt += a[j].x1;
			}
			cout << cnt;
		}
	}
	return 0;
} 
