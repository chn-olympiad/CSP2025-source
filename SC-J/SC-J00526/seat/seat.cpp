#include<iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[m*n],j=m*n;
	cin>>a[0];
	int q=a[0],sum=0;
	for(int i=1;i<j;i++)
	{
		cin>>a[i];
		if(a[i]>q) sum++;
	}
	int c,r;
	c=sum/n+1;
	if(c%2==0) r=n-sum%n;
	else r=sum%n+1;
	cout<<c<<" "<<r;
	return 0;
 } 