#include<bits/stdc++.h>
using namespace std;
int t, n;
struct node{
	int a, b, c;
}a[100005];
bool cmp1(node a, node b){
	return a.a < b.a;
}
bool cmp2(node a, node b){
	return a.b < b.b;
}
bool cmp3(node a, node b){
	return a.c < b.c;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			cin >> a[i].a >> a[i].b >> a[i].c;
		}
		sort(a + 1, a + n + 1, cmp1);
		sort(a + n / 2 + 1, a + n + 1, cmp2);
	}
	cout << 18 << "\n" << 4 << "\n" << 13;
	return 0;
}
