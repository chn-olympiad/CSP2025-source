#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[10005];
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int r=a[1];
	sort(a+1,a+n*m+1);
	int q=1;
	while(a[q]!=r)
	{
		q++;
	}
	if(q%n==0)
	{
		cout << m-q/n+1 << " ";
		if((m-q/n+1)%2==1)
			cout << 1;
		else 
			cout << n;
	}
	else
	{
		cout << m-q/n << " " ;
		if((m-q/n)%2==1)
			cout << n-q%n+1;
		else
			cout << q%n;
	}
	return 0;
}
