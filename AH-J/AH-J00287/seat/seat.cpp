#include<bits/stdc++.h>
using namespace std;
int n[110],nj[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,srjs=1,guanjian;
	cin>>a>>b;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			cin>>n[srjs];
			if(srjs==1)
			{
				guanjian=n[srjs];
			}
			srjs++;
		}
	}
	sort(n+1,n+srjs);
	for(int i=1;i<srjs;i++)
	{
		nj[i]=n[srjs-i];
	}
	srjs=1;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			if(guanjian==nj[srjs])
			{
				break;
			}
			srjs++;
		}
	}
	int chu=srjs/a,yu=srjs%a;
	if(yu==0&&chu%2==1)
	{
		cout<<chu<<" "<<a;
		return 0;
	}
	if(yu==0&&chu%2==0)
	{
		cout<<chu<<" "<<1;
		return 0;
	}
	if((chu+1)%2==0)
	{
		cout<<chu+1<<" "<<a-yu+1;
		return 0;
	}
	if((chu+1)%2==1)
	{
		cout<<chu+1<<" "<<yu;
		return 0;
	}
	return 0;
}
