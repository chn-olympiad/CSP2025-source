#include<bits/stdc++.h>
using namespace std;
int t;
struct node{
	int x, y, z;
}a[100005];
int _max(int a, int b, int c){
	return max(a, max(b, c));
}
int _min(int a, int b, int c){
	return min(a, min(b, c));
}
int celm(int a, int b){
	if(a%b==0) return a/b;
	else return a/b+1;
}
bool cmp(node a, node b){
	int d = _max(a.x, a.y, a.z);
	int d1 = _min(a.x, a.y, a.z);
	int d2;
	if(a.x!=d&&a.x!=d1) d2=a.x;
	if(a.y!=d&&a.y!=d1) d2=a.y;
	if(a.z!=d&&a.z!=d1) d2=a.z;
	int f = _max(b.x, b.y, b.z);
	int f1 = _min(b.x, b.y, b.z);
	int f2;
	if(b.x!=d&&b.x!=d1) f2=b.x;
	if(b.y!=d&&b.y!=d1) f2=b.y;
	if(b.z!=d&&b.z!=d1) f2=b.z;
	
	return (d+d2+d1) <= (f+f2+f1);
}
int main(){
//	 freopen("club.in", "r", stdin);
//	 freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		sort(a+1, a+1+n, cmp);
		int d1 = 0, d2 = 0, d3 = 0, ans = 0;
		for(int i=1;i<=n;i++){
			if(a[i].x == _max(a[i].x, a[i].y, a[i].z) && d1<n/2){
				d1++;
				ans+=a[i].x;
//				cout << a[i].x << " ";  
			}
			else if(a[i].y == _max(a[i].x, a[i].y, a[i].z) && d2<n/2){
				d2++;
				ans+=a[i].y;
//				cout << a[i].y << " ";
			}
			else if(a[i].z == _max(a[i].x, a[i].y, a[i].z) && d3<n/2){
				d3++;
				ans+=a[i].z;
//				cout << a[i].z << " ";
			}
			else if(a[i].x != _min(a[i].x, a[i].y, a[i].z) && a[i].x != _max(a[i].x, a[i].y, a[i].z) && d1<n/2){
				d1++;
				ans+=a[i].x;
//				cout << a[i].x << " ";
			}
			else if(a[i].y != _min(a[i].x, a[i].y, a[i].z) && a[i].y != _max(a[i].x, a[i].y, a[i].z) && d2<n/2){
				d2++;
				ans+=a[i].y;
//				cout << a[i].y << " ";
			}
			else if(a[i].z != _min(a[i].x, a[i].y, a[i].z) && a[i].z != _max(a[i].x, a[i].y, a[i].z) && d3<n/2){
				d3++;
				ans+=a[i].z;
//				cout << a[i].z << " ";
			}
			else if(_min(a[i].x, a[i].y, a[i].z) == a[i].x && d1<n/2){
				d1++;
				ans+=a[i].x;
//				cout << a[i].x << " ";
			}
			else if(_min(a[i].x, a[i].y, a[i].z) == a[i].y && d2<n/2){
				d2++;
				ans+=a[i].y;
//				cout << a[i].y << " ";
			}
			else if(_min(a[i].x, a[i].y, a[i].z) == a[i].z && d3<n/2){
				d3++;
				ans+=a[i].z;
//				cout << a[i].z << " ";
			}
 		}
 		cout << ans << endl;
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
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
