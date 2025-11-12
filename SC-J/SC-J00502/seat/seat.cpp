#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct node{
	int num, i;
}a[150];
int n, m;

bool cmp(node x, node y){return x.num > y.num;}

int main(){
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n * m; i++){
		cin >> a[i].num;
		a[i].i = i + 1;
	}
	sort(a, a + n * m, cmp);
	for(int i = 0; i < n * m; i++){
		if(a[i].i == 1){
			int x = i / m + 1, y;
			if((i / m) % 2 == 0) y = (i % m) + 1;
			else y = n - (i - ((i % m) + 1)) + 1;
			cout << x << ' ' << y;
			return 0;
		}
	}
	return 0;
}