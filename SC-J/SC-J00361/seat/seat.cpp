#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n,m,t,x,w,c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	t=n*m;
	for (int i=1;i<=t;i++)
	{
		cin >> a[i];
	}
	x=a[1];
	sort (a+1,a+t+1);
	for (int i=t;i>=1;i--)
	{
		w++;
		if (x==a[i])
		{
			break;
		}
	}
	c=w/n+(w%n!=0);
	r=w%n+(c%2==0);
	if (w%n==0&&c%2==1)
	{
		r=n;
	}
	cout << c << " " << r;
	fclose(stdin);
    fclose(stdout); 
	return 0;
}