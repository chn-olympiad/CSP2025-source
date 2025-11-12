#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,x2,y2;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int f=n*m;
	for(int i=1;i<=f;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+f+1);
	int mid=f-(lower_bound(a+1,a+f+1,x)-a)+1;
	//cout<<mid<<" ";
	x2=ceil((float)mid/n);
	if(x2%2==1) y2=mid-(x2-1)*n;
	else y2=n-(mid-(x2-1)*n)+1;
	cout<<x2<<" "<<y2;
	return 0;
 }
 /*
3 3
94 95 96 97 98 99 100 93 92



 */
