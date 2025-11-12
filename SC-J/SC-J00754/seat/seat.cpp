#include<bits/stdc++.h>
using namespace std;

int cmp(int a, int b) {
	return a > b;
}

int n, m, a[105], cnt, s;
int lie=1,hang;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m >> a[1];
	s = a[1];
	for (int i = 2; i <= n * m; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n*m + 1, cmp);
	for (int i = 1; i <= n * m; ++i) {
		if (a[i] == s) {
			cnt = i;
			break;
		}
	}
	while(cnt>n){
		cnt-=n;
		lie++;
	}
	hang=cnt;
	if(lie%2==1){
		cout<<lie<<" "<<hang;
	}else{
		cout<<lie<<" "<<n-hang+1;
	}
}