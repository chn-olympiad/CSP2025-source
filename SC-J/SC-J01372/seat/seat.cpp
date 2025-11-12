#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}int g=a[1],p;
	sort(a+1,a+n*m+1,greater<int>());
	for (int i=1;i<=n*m;i++){
		if (a[i]==g) p=i;
	}int x,y;
	x=ceil(double(p)/double(n));
	if (x%2==1) y=p%n;
	else y=n+1-p%n;
	if (y==0) y=n;
	cout << x << " " << y;
	return 0;
}