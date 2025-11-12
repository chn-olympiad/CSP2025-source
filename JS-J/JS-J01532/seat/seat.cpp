#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1005];
int sc;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sc=a[1];
	sort(a+1,a+n*m+1);
	int p=lower_bound(a+1,a+n*m+1,sc)-a;
	p=n*m-p+1;
	int lie=(p+(n-1))/n;
	int hang;
	p-=(lie-1)*n;
	if(lie%2==1)
	{
		hang=p;
	}
	else
	{
		hang=n-p+1;
	}
	cout<<lie<<' '<<hang;
	return 0;
}
/*
2 2
99 100 97 98
* 
2 2
98 99 100 97
*
3 3
94 95 96 97 98 99 100 93 92
*/
