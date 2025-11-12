#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int T;
int n;
struct node{
	int x , y , z;
	int cha = -1 , k;
}a[N];
bool cmp(node a , node b){
	return a.x > b.x;
}
//bool check(int x){	
//}
int main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	cin >> T;
	while(T--){
		cin >> n;
		int sum = 0;
		int is_A = 0;
		int x_num = 0 , y_num = 0 , z_num = 0;
		for(int i = 1 ; i <= n ; i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
			if(a[i].y != 0 || a[i].z != 0) is_A = 1;
			sum += max(a[i].x , max(a[i].y , a[i].z));
			if(max(a[i].x , max(a[i].y , a[i].z)) == a[i].x){
				x_num++;
			}
			else if(max(a[i].x , max(a[i].y , a[i].z)) == a[i].y){
				y_num++;
			}
			else if(max(a[i].x , max(a[i].y , a[i].z)) == a[i].z){
				z_num++;
			}
		}
		if(!is_A){
			sort(a + 1 , a + n + 1 , cmp);
			int sum = 0;
			for(int i = 1 ; i <= n / 2 ; i++) sum += a[i].x;
			cout << sum << "\n";
			continue;
		}
		if(x_num <= n / 2 && y_num <= n / 2 && z_num <= n / 2){
			cout << sum << "\n";
			continue;
		}
		else{
//			cout << "\n sum:" << sum << "\n\n\n";
			while(x_num > n / 2){
				for(int i = 1 ; i <= n ; i++){
					if(a[i].x >= a[i].y && a[i].x >= a[i].z && a[i].y >= a[i].z){
						a[i].cha = a[i].x - a[i].y;
						a[i].k = 2;
					}
					else if(a[i].x >= a[i].y && a[i].x >= a[i].z && a[i].z >= a[i].y){
						a[i].cha = a[i].x - a[i].z;
						a[i].k = 3;
					}
				}
				int minn = 2e5;
				for(int i = 1 ; i <= n ; i++){
					if(a[i].cha > -1) minn = min(minn , a[i].cha);
				}
				bool flag = 0;
				for(int i = 1 ; i <= n ; i++){
					if(flag) continue;
					if(a[i].cha == minn){
						sum -= a[i].cha;
						a[i].x = -1;
						a[i].cha = -1;
						x_num--;
						if(a[i].k == 2) y_num++;
						else z_num++;
						flag = 1;
					}
				}
			}
			while(y_num > n / 2){
				for(int i = 1 ; i <= n ; i++){
					if(a[i].y >= a[i].x && a[i].y >= a[i].z && a[i].x >= a[i].z){
						a[i].cha = a[i].y - a[i].x;
						a[i].k = 1;
					}
					else if(a[i].y >= a[i].x && a[i].y >= a[i].z && a[i].z >= a[i].x){
						a[i].cha = a[i].y - a[i].z;
						a[i].k = 3;
					}
				}
				int minn = 2e5;
				for(int i = 1 ; i <= n ; i++){
					if(a[i].cha > -1) minn = min(minn , a[i].cha);
				}
				bool flag = 0;
				for(int i = 1 ; i <= n ; i++){
					if(flag) continue;
					if(a[i].cha == minn){
						sum -= a[i].cha;
						a[i].y = -1;
						a[i].cha = -1;
						y_num--;
						if(a[i].k == 1) x_num++;
						else z_num++;
						flag = 1;
					}
				}
			}
			while(z_num > n / 2){
				for(int i = 1 ; i <= n ; i++){
					if(a[i].z >= a[i].y && a[i].z >= a[i].x && a[i].y >= a[i].x){
						a[i].cha = a[i].z - a[i].y;
//						cout << a[i].cha << " " << a[i].z << " " << a[i].y << "\n\n\n";
						a[i].k = 2;
					}
					else if(a[i].z >= a[i].y && a[i].z >= a[i].x && a[i].x >= a[i].y){
						a[i].cha = a[i].z - a[i].x;
//						cout << a[i].cha << " " << a[i].z << " " << a[i].x << "\n\n\n";
						a[i].k = 1;
					}
				}
				int minn = 2e5;
				for(int i = 1 ; i <= n ; i++){
					if(a[i].cha > -1){
						minn = min(minn , a[i].cha);
					}
//					cout << a[i].cha << " ";
				}
//				cout << "\n\n\n";
				bool flag = 0;
				for(int i = 1 ; i <= n ; i++){
					if(flag) continue;
					if(a[i].cha == minn){
						sum -= a[i].cha;
						a[i].z = -1;
						a[i].cha = -1;
						z_num--;
						if(a[i].k == 2) y_num++;
						else x_num++;
						flag = 1;
					}
				}
			}
			cout << sum << "\n";
		}
//		int l = 0 , r = 6e4 + 5;
//		while(l < r){
//			int mid = l + r + 1 >> 1;
//			if(check(mid)) l = mid + 1;
//			else r = mid;
//		}
//		cout << l;
	}
	return 0;
} 
/*
5
10
2020 14533 18961
2423 15344 16322
1910 6224 16178
2038 9963 19722
8375 10557 5444
3518 14615 17976
6188 13424 16615
8769 509 4394
958 3195 9953
16441 5313 10926
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042
10
3004 4255 17336
11894 5756 17092
8150 14715 10991
5149 16652 16780
11524 11996 5433
7690 10472 19935
1184 6516 9246
3231 5570 10010
8426 16992 4654
18955 13977 16657
10
6839 5455 15586
11767 12919 2643
13775 8904 19938
13717 11997 15170
13707 2404 17497
3471 2462 8073
18467 14346 18663
13582 4839 15785
11875 7476 12308
8568 3134 18522
10
14230 3941 18854
12173 19429 15426
10974 4717 15290
4732 6608 4961
13198 13925 2137
10688 3092 16965
5356 19920 1471
11299 10796 13511
17932 12143 16407
5611 8100 16107


*/
