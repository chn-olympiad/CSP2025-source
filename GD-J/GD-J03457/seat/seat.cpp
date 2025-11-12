#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505;
int n,m,a[N],tmp;
bool cmp(int a,int b){
	return a > b;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	tmp = a[1];
	sort(a + 1,a + 1 + n * m,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == tmp){
			tmp = i;
			break;
		}
	}
	--tmp;
	int x = (tmp) / n + 1;
	int y = (x % 2 ? (tmp % n + 1) : (n - tmp % n));
	cout << x << ' ' << y;
	return 0;
}
