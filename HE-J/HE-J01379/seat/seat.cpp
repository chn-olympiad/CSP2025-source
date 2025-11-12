#include<bits/stdc++.h>
using namespace std;
int n,m,na=1,ma=0,b=0;
int a[150];
int ar;
bool cmp(int a,int b)
{
	if(a>b)
	{
		return true;
	}
	return false;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	ar=a[1];
	sort(a+1,a+n+m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(ma==n&&b==1)
		{
			na++;
		}
		if(na%2!=0)
		{
			if(ma<=n)
			{
				ma++;
			}
			if(ma==n)
			{
				b=1;
			}
		}
		else if(na%2==0)
		{
			if(ma==n)
			{
				b==2;
			}
			else if(b==1&&ma>=1)
			{
				ma--;
			}
		}
		//cout<<na<<" "<<ma<<endl;
		if(a[i]==ar)
		{
			cout<<na<<" "<<ma;
			return 0;
		}
		
	}
	return 0;
}
