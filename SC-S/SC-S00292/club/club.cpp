#include <bits/stdc++.h>
using namespace std;
struct node{
	int x, y, z;
};
node a[100005];
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w", stdout);
	int n;
	int t;
	cin >> t;
	while (t--){
		memset(a, 0, sizeof(a)); 
		cin >> n;
		int ans=0;
		for (int i=1; i<=n; i++) {
			cin >> a[i].x >> a[i].y >> a[i].z;
			ans += a[i].x;
		}
		cout << ans;
	}
	return 0;
}
//#include <bits/stdc++.h>
//using namespace std;
//struct node{
//	int x, y, z;
//};
//node a[100005];
//int f1[100005], f2[100005];
//int main() {
////	freopen("club.in","r",stdin);
////	freopen("club.out","w", stdout);
//	int n;
//	int t;
//	cin >> t;
//	while (t--){
//		memset(a, 0, sizeof(a)); 
//		memset(f1, 0, sizeof(f1));
//		memset(f2, 0, sizeof(f2));
//		cin >> n;
//		for (int i=1; i<=n; i++) {
//			cin >> a[i].x >> a[i].y >> a[i].z;
//		}
//		for (int i=1; i<=n; i++) {
//			for (int v=n/2; v>=min(a[i].x, a[i].y); v--) {
//				bool flag1, flag2;
//				int c = max(f1[v], f1[v-1]+a[i].x);
//				if (c == f1[v]) flag1 = 1;
//				int d = max(f2[v], f2[v-1]+a[i].y);
//				if (d == f2[v]) flag2 = 1;
//				if (max(c, d) == c) {
//					f1[v] = c;
//					if (flag1 == 1) f2[v] = d;
//				}
//				else {
//					f2[v] = d;
//					if (flag2 == 1) f1[v] = c;
//				}
//			}
//		}
////		for (int i=1; i<=n/2; i++) cout << f1[i] << " ";
////		cout << endl;
////		for (int i=1; i<=n/2; i++) cout << f2[i] << " ";
////		cout << endl;
////		for (int i=1; i<=n/2; i++) cout << f3[i] << " ";
////		cout << endl;
//		cout << f1[n/2]+f2[n/2] << endl;
//	}
//	return 0;
//}
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
//#include <bits/stdc++.h>
//using namespace std;
//int n;
//int ans;
//int t;
//struct node{
//	int x, y, z;
//	int whetherx, whethery, whetherz;
//};
//node a[100005];
//node number;
//bool cmp1(node c, node d) {
//	return c.x>d.x;
//}
//bool cmp2(node c, node d) {
//	return c.y>d.y;
//}
//bool cmp3(node c, node d) {
//	return c.z>d.z;
//}
//int main() {
//	freopen("club.in","r",stdin);
//	freopen("club.out","w", stdout);
//	cin >> t;
//	while (t--) {
//		ans = 0;
//		cin >> n;
//		for (int i=1; i<=n; i++) {
//			cin >> a[i].x >> a[i].y >> a[i].z;
//			if (a[i].x <= a[i].y) {
//				if (a[i].x<=a[i].z) {
//					a[i].whetherx = 0;
//					if (a[i].y > a[i].z) {
//						a[i].whethery = 3;
//						a[i].whetherz = 2;
//					}
//					else {
//						a[i].whethery = 2;
//						a[i].whetherz = 3;
//					}
//				}
//			}
//			if (a[i].y <= a[i].x && a[i].y<=a[i].z) {
//				a[i].whethery = 0;
//				if (a[i].x > a[i].z) {
//					a[i].whetherx = 3;
//					a[i].whetherz = 2;
//				}
//				else {
//					a[i].whetherx = 2;
//					a[i].whetherz = 3;
//				}
//			}
//			if (a[i].z <= a[i].y && a[i].z<=a[i].x) {
//				a[i].whetherz = 0;
//				if (a[i].y > a[i].x) {
//					a[i].whethery = 3;
//					a[i].whetherx = 2;
//				}
//				else {
//					a[i].whethery = 2;
//					a[i].whetherx = 3;
//				}
//			}
//			number.x += a[i].x;
//			number.y += a[i].y;
//			number.z += a[i].z;
//		}
//		if (number.x > number.y&&number.x>number.z) {
//			sort(a+1, a+1+n, cmp1);
//			for (int i=1; i<=n/2; i++) {
//				ans+=a[i].x;
//				a[i].y == 0;
//				a[i].z == 0;
//			}
//			number.y = 0;
//			number.z = 0;
//			for (int i=1; i<=n; i++) {
//				number.y += a[i].y;
//				number.z += a[i].z;
//			}
//			if (number.y > number.z) {
//				sort(a+1, a+1+n, cmp2);
//				for (int i=1; i<=n/2; i++) {
//					ans+=a[i].x;
//					a[i].z == 0;
//				}
//			}
//			sort(a+1, a+1+n, cmp3);
//			for (int i=1; i<=n/2; i++) {
//				ans+=a[i].x;
//				a[i].y == 0;
//				a[i].z == 0;
//			}
//		}
//	}
//	return 0;
//}
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