#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
int a[10000];
int flag;
bool cmp(int a,int b)
{
	if(a>b)
	{
		return true;
	}
	if(a<b)
	{
		return false;
	}
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		if(i==1)
		{
			cin>>a[i];
			flag=a[i];
		}
		else
		{
			cin>>a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	int nowplace;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flag)
		{
			nowplace=i;
		}
	}
	int hang,lie;
	if(nowplace%n==0)
	{
		lie=nowplace/n;
	}
	else if(nowplace%n!=0)
	{
		lie=nowplace/n+1;
	}
	if((nowplace%n)!=0)
	{
		if((nowplace/n)%2==0)
		{

			hang=nowplace%n;			
		}
		else if((nowplace/n)%2==1)
		{
			hang=n-(nowplace%n)+1;
		}
	}
	else if((nowplace%n)==0)
	{
		if((nowplace/n)%2==0)
		hang=1;
		if((nowplace/n)%2==1)
		hang=n;
	}
	cout<<lie<<" "<<hang;
	return 0;
}