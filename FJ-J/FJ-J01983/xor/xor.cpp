#include<iostream>
using namespace std;
int a[500001];

bool v[500001];

main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i] == k)
		{
			ans++;
			v[i]=true;
		}
	}
	int m,post;
	for(int i=1;i<=n;i++)
	{
		if(v[i] == false)
		{
			m=a[i];
			post=i;
			break;
		}
	}
	for(int i=post+1;i<=n;i++)
	{
		if(v[i] == false)
		{
			m^=a[i];
			if(m == k)
			{
				ans++;
				for(int j=i;j<=n;j++)
				{
					if(v[j] == false)
					{
						m=a[j];
						i=j+1;
						break;
					}
				}
			}
		}
		else
		{
			for(int j=i;j<=n;j++)
			{
				if(v[j] == false)
				{
					m=a[j];
					i=j+1;
					break;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
