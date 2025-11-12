#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int a[115],n,m,ex;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	ex=a[0];
	sort(a,a+n*m,cmp);
	int l=0,r=m*n,mid,x,y;
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid-1]<ex)
		{
			r=mid-1;
		}
		if(a[mid-1]>ex)
		{
			l=mid+1;
		}
		if(a[mid-1]==ex) break;
	}
	if(mid%n==0)
	{
		x=mid/n;
	}
	else
	{
		x=(mid/n)+1;
	}
	if(x%2!=0)
	{
		y=mid-(n*(x-1));
	}
	else
	{
		if((mid-n*(x-1))==1) y=n;
		else y=n-(mid-(n*(x-1)));
	}
	cout<<x<<" "<<y;
	return 0;
} 
