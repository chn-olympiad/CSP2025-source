#include <bits/stdc++.h>
using namespace std;
int n,m;
struct q
{
	bool yn=false;
	int sum=0;
}a[101];
bool cmp(q a1,q a2)
{
	return a1.sum>a2.sum;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i].sum;
	a[1].yn=true;
	sort(a+1,a+n*m+1,cmp);
	int k=0;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].yn==true) k=i;
	}
	int x,y;
	x=(k-1)/n+1;
	y=x*n-k+1;
	if(x%2==1) y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
/*
2 2
99 100 98 97
3 3
94 95 96 97 98 99 100 93 92
*/
//¸øµã·Ö°É 
