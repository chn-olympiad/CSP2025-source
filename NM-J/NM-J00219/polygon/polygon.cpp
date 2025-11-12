#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=0;
int main()
{
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=10;i++)
	{
		cin>>ans;
		if(ans==0)
		{
			if(ans==1)
			{
				ans++;
			 } 
			continue;
		}
		else
		{
			printf("/n");
		}
	 }
	for(int i=1;i<=10;i++)
	{
		if(ans==0)
		{
			if(ans==1)
			{
				ans++;
			 } 
			continue;
		}
		else
		{
			for(int j=1;j<=10;j++)
			{
				if(ans==0)
				{
					if(ans==1)
					{
						ans++;
			 		} 
					continue;
				}
				else
				{
					printf("/n");
				}
	 		}
		}
	 }
    cout<<n<<m; 
}
