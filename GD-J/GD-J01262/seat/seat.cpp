#include<bits/stdc++.h>
using namespace std;
int a[110];
int w(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,student,xh,hang,lie;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	student=a[1];
	sort(a+1,a+n*m+1,w);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==student)
		{
			xh=i;
			break;
		}
	}
	lie=xh/n;
	if(xh%n!=0)
	{
		lie++;
	}
	cout << lie << " ";
	hang=xh%n;
	if(hang==0)
	{
		hang=n;
	}
	if(lie%2==0)
	{
		hang=n-hang+1;
	}
	cout << hang;
	return 0;
}
