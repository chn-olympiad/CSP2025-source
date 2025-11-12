#include<bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct S{
	int sum, id;
}a[maxn];
bool cmp(S a, S b){
	return a.sum > b.sum;
}
int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i].sum;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + n * m, cmp);
	int x = 1, y = 1, p = 0;
	for(int i = 1;i <= n * m;i++){
		if(a[i].id == 1){
			cout << y << ' ' << x;
			return 0;
		}
		if(p == 0){
			x++;
			if(x > n) x = n, p = 1, y++;
		}else{
			x--;
			if(x < 1) x = 1, p = 0, y++;
		}
	}
	return 0;
}