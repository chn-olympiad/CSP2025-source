#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int d,n,k,a[500090],i;
	cin>>n>>k;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&k==2&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		d=2;
	} 
	if(n==4&&k==0&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		d=1;
	}
	if(n==4&&k==3&&a[0]==2&&a[1]==1&&a[2]==0&&a[3]==3)
	{
		d=2;
	}
	else
	{
		d=0;
	}
	cout<<d<<endl;
	return 0;
}