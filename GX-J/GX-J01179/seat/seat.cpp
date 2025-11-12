#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
struct node{
	int sroce,id;
}a[N];
bool cmp(node a,node b){
	return a.sroce > b.sroce;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i){
		cin >> a[i].sroce;
		a[i].id = i;
	}
	sort(a + 1,a + 1 + (n * m),cmp);
	int i = 1,j = 1,now = 1;
	while(i <= n && j <= m){
		if (j % 2 == 1){
			if (a[now].id == 1){
				cout << j << ' ' << i;
				return 0;
			}
			if (i == n){
				++j;
			}else{
				++i;
			}
			++now;
		}else{
			if (a[now].id == 1){
				cout << j << ' ' << i;
				return 0;
			}
			if (i == 1){
				++j;
			}else{
				--i;
			}
			++now;
		}
	}
	return 0;
}
