#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
		cin >> a[i];
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int c=1,r=1;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			cout << c << " " << r;
			return 0;
		}
		if (c%2==1)
			r++;
		else
			r--;
		if (r>n)
			c++,r--;
		else if (r<1)
			c++,r++;
	}
	return 0;
}
