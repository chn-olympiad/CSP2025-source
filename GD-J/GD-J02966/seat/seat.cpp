#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+100;
int n,m;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i].num;
		a[i].id=i;
		if (i==1) R=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int Get_id=R.id,aa=0;;
	for (int i=1;i<=n*m;i++)
	{
		if (a[i].id==Get_id)
		{
			aa=i;
		}
	}
//	cout<<aa<<endl; 
	int x=0,y=0;
	if (aa%m==0) x=aa/m;
	else x=aa/m+1;
	if (x%2==0)
	{
		y=m-(aa%m)+1;
		if (aa%m==0) y=m;
	}
	else
	{
		y=aa%m;
		if (y==0) y=m;
	}
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 97 98
3 3
94 95 96 97 98 99 100 93 92
5 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
*/
