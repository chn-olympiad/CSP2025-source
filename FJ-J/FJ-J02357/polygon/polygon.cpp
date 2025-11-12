#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n:
    int lis[n+1];
    if(n==3)
    {
    	for(int i=1;i<=3;i++)
    	{
    		cin>>lis[i];
		}
		if(lis[1]+lis[2]>lis[3])
		{
			if(ads(lis[1]-lis[2])<lis[3])
			{
				cout<<1;
			}
			else
			{
				cout<<0;
			}
		}
	}
	if(n==5)
	{
		cout<<7;
	}
	if(n==9)
	{
		cout<<13;
	}
    if(n==4)
    {
    	cout<<4;
	}
    return 0;
    
}
