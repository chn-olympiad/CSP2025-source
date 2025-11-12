#include<bits/stdc++.h>
using namespace std;
int a[99999];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin) ;
	freopen("seat.out","w",stdout) ;
	int n,m,d;
	cin>>n>>m;
	int c=n*m;
	for(int i=1;i<=c;i++)
	{
		cin>>a[i];
		if(i==1)d=a[i];
	}
	sort(a+1,a+c+1,cmp);
	int sum;
	for(int i=1;i<=c;i++)
	{
		if(a[i]==d)sum=i;
	}
	int dd=n*2;
	int ee=sum%dd;
	int ww=sum/dd;
	if(ee<=n&&ee>=1)
	{
		cout<<2*ww+1<<" "<<ee;	
	}
	if(ee>=n+1)
	{
		cout<<2*ww+2<<" "<<2*n-ee+1;
	}
	if(ee==0)
	{
		cout<<2*ww<<" "<<"1";
	}
	return 0;
} 