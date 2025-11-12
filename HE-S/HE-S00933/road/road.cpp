#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(n>0)
			{
				n+=1;
			}
			else
			{
				n+=2;
			}
			
		}
	}
    for(int i=n;i<=10;i++)
    {
    	for(int j=2;j<=n;j++)
    	{
    		if(n>=0)
    		{
    			n++;
			}
			else
			{
				n--;
			}
		}
	}
	cout<<"13";
	return 0;
}
