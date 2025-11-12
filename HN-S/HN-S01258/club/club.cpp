#include <bits/stdc++.h>
using namespace std;
long long t , n , a[5] , cnt , sum[100005];
struct stu{
	long long nu , id;
}p[100005][5];
int main(){
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	cin >> t;
	while (t --){
		cin >> n;
		memset (p , 0 , sizeof (p));
		memset (a , 0 , sizeof (a));
		cnt = 0;
		for (int i = 1; i <= n; i ++){
			cin >> p[i][1].nu >> p[i][2].nu >> p[i][3].nu;
			if (p[i][2].nu >= p[i][1].nu && p[i][2].nu >= p[i][3].nu){
				swap (p[i][1].nu , p[i][2].nu);
				p[i][1].id = 2;
				p[i][2].id = 1;
				if (p[i][2].nu < p[i][3].nu){
					swap (p[i][2].nu , p[i][3].nu);
					p[i][2].id = 3;
					p[i][3].id = 1;
				}else p[i][3].id = 3;
				a[2] ++;
			}else if (p[i][3].nu >= p[i][1].nu && p[i][3].nu >= p[i][2].nu){
				swap (p[i][1].nu , p[i][3].nu);
				p[i][1].id = 3;
				p[i][3].id = 1;
				if (p[i][3].nu >= p[i][2].nu){
					swap (p[i][3].nu , p[i][2].nu);
					p[i][3].id = 2;
					p[i][2].id = 1;
				}else p[i][2].id = 2;
				a[3] ++;
			}else{
				p[i][1].id = 1;
				if (p[i][2].nu < p[i][3].nu){
					swap (p[i][2].nu , p[i][3].nu);
					p[i][2].id = 3;
					p[i][3].id = 2;
				}else{
					p[i][2].id = 2;
					p[i][3].id = 3;
				} 
				a[1] ++;
			}
			//cnt += max (p[i][1].nu , max (p[i][2].nu , p[i][3].nu));
			cnt += p[i][1].nu;
		}
		///////////////////////////////////////////////////////////////////////////////////////////
		if (a[1] > n / 2){
			int j = a[1] - n / 2;
			memset (sum , 0 , sizeof (sum));
			for (int i = 1; i <= n; i ++){
				if (p[i][1].id != 1){
					sum[i] = 2147483647;
					continue;
				}
				sum[i] = p[i][1].nu - p[i][2].nu;
			}
			sort (sum + 1 , sum + 1 + n);
			for (int i = 1; i <= j; i ++) cnt -= sum[i];
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}else if (a[2] > n / 2){
			int j = a[2] - n / 2;
			memset (sum , 0 , sizeof (sum));
			for (int i = 1; i <= n; i ++){
				if (p[i][1].id != 2){
					sum[i] = 2147483647;
					continue;
				}
				sum[i] = p[i][1].nu - p[i][2].nu;
			}
			sort (sum + 1 , sum + 1 + n);
			for (int i = 1; i <= j; i ++) cnt -= sum[i];
			/////////////////////////////////////////////////////////////////////////////////////
		}else{
			int j = a[3] - n / 2;
			memset (sum , 0 , sizeof (sum));
			for (int i = 1; i <= n; i ++){
				if (p[i][1].id != 3){
					sum[i] = 2147483647;
					continue;
				}
				sum[i] = p[i][1].nu - p[i][2].nu;
			}
			sort (sum + 1 , sum + 1 + n);
			for (int i = 1; i <= j; i ++) cnt -= sum[i];
		}
		cout << cnt << endl;
	}
	return 0;
}
/*
1
2
10 9 8
4 0 0
*/
