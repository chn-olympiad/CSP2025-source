#include <bits/stdc++.h>
using namespace std;

int a[110];
bool cmp(int x, int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;//行  列 
	cin >> n >> m;
	int R;
	cin >> R;
	a[1] = R;
	for(int i = 2; i<=n*m; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n*m+1, cmp);
//	cout << "debug: ";
//	for(int i = 1; i<=n*m; i++) {
//		cout << a[i] <<" ";
//	}
//	cout << "\n";
	int num;
	for(int i = 1; i<=n*m; i++) {
		if(a[i] == R) {
			num = i;
			break;
		}
	}
	int x = num/n;//lie
	int y = num%n;//hang
	if(num%n!= 0) x++;
	else y = n;
	if(x%2 == 0) {
		y = n-y;
		if(y == 0) y = 1;
	}
	cout << x <<" " << y <<"\n";
	return 0;
}
//csp不会真的是这样排的吧
/*
是不是考前没拜y总导致的两题没写啊
中午拜一下吧
下午的S组要好好考啊 
*/ 
