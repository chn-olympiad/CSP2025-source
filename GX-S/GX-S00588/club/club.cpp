#include <bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c, d, e, f, g, i, c1, c2, c3;
}a[100005];
int c1[50005], c2[50005], c3[50005];
int n, b;
bool cmp(node x, node y){
	return x.i < y.i;
}
bool cmp1(node x, node y){
	return x.d > y.d;
}
bool cmp2(node x, node y){
	return x.e > y.e;
}
bool cmp3(node x, node y){
	return x.f > y.f;
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		int f = 0;
		cin >> b;
		for(int j = 1; j <= b; j++){
			cin >> a[j].a >> a[j].b >> a[j].c;
			a[j].d = a[j].a - max(a[j].b, a[j].c);
			a[j].e = a[j].b - max(a[j].c, a[j].a);
			a[j].f = a[j].c - max(a[j].b, a[j].a);
			a[j].g = 4;
			a[j].i = j;
		}
		sort(a + 1, a + 1 + b, cmp1);
		for(int j = 1; j <= b / 2; j++) a[j].g = 1;
		sort(a + 1, a + 1 + b, cmp2);
		for(int j = 1; j <= b / 2; j++){
			if(a[j].g == 1){
				if(a[j].b > a[j].a) a[j].g = 2;
				continue;
			}
			a[j].g = 2;
		}
		sort(a + 1, a + 1 + b, cmp3);
		for(int j = 1; j <= b / 2; j++){
			if(a[j].g == 1){
				if(a[j].c > a[j].a) a[j].g = 3;
				continue;
			}
			if(a[j].g == 2){
				if(a[j].c > a[j].b) a[j].g = 3;
				continue;
			}
			a[j].g = 3;
		}
		sort(a + 1, a + 1 + b, cmp); 
		for(int j = 1; j <= b; j++){
			if(a[j].g == 1) f += a[j].a;
			if(a[j].g == 2) f += a[j].b;
			if(a[j].g == 3) f += a[j].c;
		}
		cout << f << endl;
		f = 0;
	}
	return 0;
}
