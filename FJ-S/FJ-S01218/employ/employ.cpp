#include<iostream>
using namespace std;
int n,m,ans,mark,mine,little=1,ng=0,np,luqu=0,count;
int naixin[10005];
string nandu;
int main()
{
	cin>>n>>m;
	cin>>nandu;
	for (int i=1;i<=n;i++)
	{
		cin>>naixin[i];
	}
	for (int i=1;i<=n;i++)
	{
		ans=-999;
		mark=0;
		for (int j=i;j<=n;j++)
		{
			if (ans>naixin[j])
			{
				ans=naixin[j];
				mark=j;
			}
		}
		mine=naixin[i];
		naixin[i]=naixin[mark];
		naixin[mark]=naixin[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (nandu[i]=='1')
		{
			np=0;
			while(naixin[little]<ng)
			{
				little++;
				if (little>n)
				{
					np=1;
					break;
				}
			}
			if (np=0)
			{
				little++;
				luqu++;
				ng=0;
			}
			else
			{
				ng++;
			}
		}
		else
		{
			ng++;
			
		}
	}
	if (luqu>=m)
	{
		count++;
	}
	cout<<count;
	return 0;
}
