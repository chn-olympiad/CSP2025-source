#include<bits/stdc++.h>
using namespace std;
int n,m,a,x,c=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n;
	cin >>m;
	cin>>a;
	for (int i=2;i <=n*m;i++)
	{
		cin >>x;
		if(x>a)
		c++;
	}
	cout <<(c+n-1)/n<<' ';
	if ((c+n-1)/n)
	{
		cout <<c%(2*n);
		return 0;
	}
	else
	cout <<((c+n-1)*n+1)-c;
	return 0;
}
