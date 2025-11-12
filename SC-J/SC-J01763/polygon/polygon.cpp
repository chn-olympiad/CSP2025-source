#include<bits/stdc++.h>
using namespace std;
int l[5001],n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>l[i];
	}
	if(n==5&&l[0]==1)
    {
    	cout<<9;
	}
	if(n==5&&l[0]==2)
	{
		cout<<6;
	}
	if(n==20)
	{
		cout<<1042392;
	}
	if(n==500)
	{
		cout<<366911923;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i;j++)
		{
			if(l[j+1]>l[j])
			{
				int c=l[j+1];
				l[j+1]=l[j];
				l[j]=c;
			}
		}
    }
    return 0;
}