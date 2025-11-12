#include<bits/stdc++.h>//freoepn
using namespace std;
int a[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int zong=n*m;
	for(int i=1;i<=zong;i++)
	{
		cin>>a[i];
	}
	int r=a[1],wei;
	sort(a,a+zong+1);
	for(int i=1;i<=zong;i++)
	{
		if(a[i]==r)
		{
			wei=i;
			break;
		}
	}
	wei=zong-wei+1;
	//cout<<wei<<endl;
	int lie=wei/n;
	int yu=wei-lie*n;
	//cout<<lie<<" "<<yu<<endl;
	if(yu==0)
	{
		if(lie%2==0)
		{
			cout<<lie<<" "<<"1";
		}
		else
		{
			cout<<lie<<" "<<n;
		}
	}
	else
	{
		lie+=1;
		if(lie%2==0)
		{
			cout<<lie<<" "<<n-yu+1;
		}
		else
		{
			cout<<lie<<" "<<yu;
		}
	}
	return 0;
}