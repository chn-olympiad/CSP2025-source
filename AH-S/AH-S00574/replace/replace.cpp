#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int flag=0;
	for(int a=1;a<=10;a++)
	{
		for(int b=1;b<=10;b++)
		{
			for(int n=1;n<=10;n++)
			{
				for(int c=1;c<=10;c++)
				{
					long long ans=a;
					for(int i=1;i<=n;i++)
					{
						ans=ans*b;
						ans=ans%c;
					}
					long long k=a;
					for(int i=1;i<=n;i++)
					{
						k*=b;
					}
					int l=k%c;
					if(ans==l)
					{
						flag++;
					}
					
				}
			}
		}
	}
	cout<<flag;
	return 0;
}
