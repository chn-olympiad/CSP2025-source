#include<bits/stdc++.h>
using namespace std;
int t, ans = 0;

struct node{
	int c1, c2, c3;
}a[100005];

bool cmp1(node a, node b){
	return a.c1 > b.c1;
}

int main(){
	freopen("club2.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int maxn = n/2;
		for(int i = 1; i <= n; i++){
			cin >> a[i].c1 >> a[i].c2 >> a[i].c3;
		}
		sort(a+1, a+n+1, cmp1);
		for(int i = 1; i <= maxn; i++){
			ans += a[i].c1;
		}
		cout << ans << endl;
	}
	return 0;
}
