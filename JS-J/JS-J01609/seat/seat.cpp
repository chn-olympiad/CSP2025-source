#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 10,M = 10;
int n,m,a[N * M + 5];

bool cmp(int a,int b){
	return a > b;
}

signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++){
		cin >> a[i];
	}
	int now = a[1],w = 0;
	sort(a + 1,a + n * m + 1,cmp);
	for(int i = 1;i <= n * m;i++){
		if(a[i] == now)
			w = i;
	}
	int x = (w + n - 1) / n,y = 0;
	if(x % 2 == 1){
		y = w % (2 * n);
	}
	else{
		y = n - (w - (x - 1) * n) + 1;
	}
	cout << x << " " << y << "\n";
	return 0;
}
