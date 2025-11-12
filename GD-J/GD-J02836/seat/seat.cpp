#include<bits/stdc++.h>
using namespace std;
int n, m, a[100], x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++)
		cin >> a[i];
	x=a[0];
	sort(a,a+n*m,greater<int>());
	for(int i=0;i<n*m;i++)
		if(a[i]==x)
		{
			cout << i/n+1 << " " << ((i/n)&1?m-i%n:i%n+1);
			break;
		}
	return 0;
}
