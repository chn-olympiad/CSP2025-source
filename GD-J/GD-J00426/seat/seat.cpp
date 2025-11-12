#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105]={},r,r1=0;
	cin >> n >> m >> r;
	a[r]++;
	for (int i=2;i<=n*m;i++){
		int j;
		cin >> j;
		a[j]++;
	}
	for (int i=100;i>=r;i--)
		r1+=a[i];
	if (r1%n==0){
		cout << r1/n << " ";
		if (r1/n%2==1)
			cout << n;
		else
			cout << 1;
	}
	else{
		cout << r1/n+1 << " ";
		if ((r1/n+1)%2==1)
			cout << r1%n;
		else
			cout << n-r1%n+1;
	}
	
	return 0;
}
