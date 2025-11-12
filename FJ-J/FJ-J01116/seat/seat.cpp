#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105],R;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int su=n*m;
	for(int i=1;i<=su;i++)
	{
		cin>>a[i];
	}
	R=a[1];
	int loc=0;
	sort(a+1,a+1+su,cmp);
	for(int i=1;i<=su;i++)
	{
		if(a[i]==R)
		{
			loc=i;
			break;
		}
	}
	int lie=ceil(1.0*loc/n);
	int ad;
	if(loc%n==0)
	{
		ad=n;
	}
	else
	{
		ad=loc-(loc/n)*n;
	}
//	cout<<loc<<" "<<ad<<" "<<lie<<" "<<R<<"\n";
//	for(int i=1;i<=su;i++)
//	{
//		cout<<a[i]<<" ";
//	}
//	cout<<endl;
	cout<<lie<<" ";
	if(lie%2==1)
	{
		cout<<ad;
	}
	else
	{
		cout<<n-ad+1;
	}
	return 0;
}
