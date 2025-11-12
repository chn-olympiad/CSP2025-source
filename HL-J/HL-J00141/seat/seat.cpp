#include<bits/stdc++.h>
using namespace std;
const int N = 200;
long long n,m,x,y,k,a[N];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++) {
		cin>>a[i];
	}
	int t = a[1];//fenshu
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	for(int i=1; i<=n*m; i++) {
		if(t==a[i]) {
			k=i;//mingci
			break;
		}
	}
	if(k<=n)
	{
		x = k;
		y = 1;
	}
	else
	{
		x = k%n;
		y = k/m+1;
	}
	if(n%2==1)
	{
		if(n+1/2==n)
		{
			x = x;
		}
		else
		{
			x = n-x;
		}
	}
	else
	{
		x = x+1;
	}
	cout<<y<<" "<<x;

	return 0;
}
