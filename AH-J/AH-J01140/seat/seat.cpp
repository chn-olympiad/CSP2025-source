#include<bits/stdc++.h>
using namespace std;

int a[105];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	cin>>n>>m;
	int t = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>a[t];
			t++;
		}
	}
	int R = a[1];
	int r1;
	sort(a + 1, a + t);
	for(int i = 1; i <= m * n; i++){
		if(a[i] == R){
			r1 = m * n - i + 1;
			break;
		}
	}
	int c;
	if(r1 % n == 0) c = r1 / n;
	else c = r1 / n + 1;
	cout<<c<<" ";
	if(c % 2 == 1 && r1 % n != 0) cout<<r1 % n;
	else if(c % 2 == 1 && r1 % n == 0) cout<<n;
	else if(c % 2 == 0 && r1 % n != 0) cout<<n - (r1 % n) + 1;
	else cout<<1;
	return 0;
}
