#include<bits/stdc++.h>
using namespace std;
int T, n;
int cclub1 = 0;
int cclub2 = 0;
int cclub3 = 0;
struct node{
	int sum1 = 0, sum2 = 0, sum3 = 0, isok = 1;
};
node a[100005];
int max1(node x){
	return max(max(x.sum1, x.sum2), x.sum3);
}
int max3(node x){
	return min(min(x.sum1, x.sum2), x.sum3);
}
int max2(node x){
	int ax[4] = {x.sum1, x.sum2, x.sum3};
	sort (ax, ax + 3);
	return ax[1];
}bool cmp1(node x, node y){
	return x.sum1 > y.sum1;
}
bool cmp2(node x, node y){
	return x.sum2 > y.sum2;
}
bool cmp3(node x, node y){
	return x.sum3 > y.sum3;
}
bool cmp11(node x, node y){
	return abs(x.sum1 - max2(x)) < abs(y.sum1 - max2(x));
}
bool cmp22(node x, node y){
	return abs(x.sum2 - max2(x)) < abs(y.sum2 - max2(x));
}
bool cmp33(node x, node y){
	return abs(x.sum3 - max2(x)) < abs(y.sum3 - max2(x));
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --){
		cclub1 = 0, cclub2 = 0, cclub3 = 0;
		int sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i ++) {
			a[i].isok = 1;
			cin >> a[i].sum1 >> a[i].sum2 >> a[i].sum3;
		}
		sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum1 == max1(a[i]) && a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum2 == max1(a[i]) && a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum3 == max1(a[i]) && a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum1 == max2(a[i]) && a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum2 == max2(a[i]) && a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum3 == max2(a[i]) && a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}sort(a + 1, a + n + 1, cmp1);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum1 == max3(a[i]) && a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp2);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum2 == max3(a[i]) && a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp3);
		for (int i = 1; i <= n; i ++) {
			if (a[i].sum3 == max3(a[i]) && a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}
		int ans = 0;
		ans += sum;
		sum = 0;
		cclub1 = 0, cclub2 = 0, cclub3 = 0;
		for (int i = 1; i <= n; i ++) {
			a[i].isok = 1;
		}
		sort(a + 1, a + n + 1, cmp11);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp22);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp33);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}sort(a + 1, a + n + 1, cmp11);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp22);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp33);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}sort(a + 1, a + n + 1, cmp11);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub1 < n / 2) {
				cclub1 ++;
				sum += a[i].sum1;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp22);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub2 < n / 2) {
				cclub2 ++;
				sum += a[i].sum2;
				a[i].isok = 0;
			}
		}
		sort(a + 1, a + n + 1, cmp33);
		for (int i = 1; i <= n; i ++) {
			if (a[i].isok == 1 && cclub3 < n / 2) {
				cclub3 ++;
				sum += a[i].sum3;
				a[i].isok = 0;
			}
		}
		ans = max(sum, ans);
		cout << ans << endl;
	}
	return 0;
}
//应该是最后一次csp了,想进迷惑行为大赏,CCF,LUOGU,KKK,用3年阳寿换csp-j2025一等
