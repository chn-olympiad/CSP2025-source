#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,c,r,sum;
	int a[101];
	cin>>n;
	cin>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++)
	{
		cin>>a[i]; 
	}
	for(int j=1;j<=sum;j++)
	{
		if(a[1]>=a[j])
		{
			c=1;
			r=1;
		} 
		if(a[1]<a[j])
		{
			r++;
		}
		 if(r>n)
		 {
			c++;
			r--; 
		 }
	}
	cout<<c<<","<<r;
	return 0;
}
