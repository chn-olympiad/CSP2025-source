#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[101];
int cmp (int a,int b){
	return a > b;
}
int main ()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=0;i<n*m;i++) cin >> a[i];
	int sum = a[0];
	sort (a,a+n*m,cmp);
	for (int i=0;i<n*m;i++){
		if (a[i] == sum) sum = i+1;
	}
	cout << (sum-1)/m+1 << " ";
	if((sum-1)/m % 2 != 0) cout << m-(sum-1)%m;
	else {
		if (sum % m == 0) cout << m;
		else cout << sum%m;
	}
	return 0;
}
