#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000],i=0;
bool flag[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>a[i])
	{
		if(flag[a[i]]==0)
		{
			b[a[i]]=a[i];
			flag[a[i]]==1;
		}
		else
		{
			for(int j=b[i]; j<10; j++)
			{
				if(flag[j]==0)
				{
					b[a[j]]=a[i];
					flag[a[j]]=1;
				}
			}
		}
	}
	for(int i=1000; i>1; i--)
	{
		if(flag[b[i]]==0)
		{
			cout<<"";
		}
		else
		{
			cout<<b[i];
		}
	}
	return 0;
}
