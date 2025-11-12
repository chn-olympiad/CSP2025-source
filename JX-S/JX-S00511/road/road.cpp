#include <bits/stdc++.h>
using namespace std;
int n,m,k,t[1000005][5],a[15][10005],town[10005],con[15],sum;
int main()
{
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=2;j++)
		{
			cin >> t[i][j];
			for(int h=1;h<=n;h++)
			{
				if(t[i][j]==h)
				{
					town[h]++;//city number
					break;
				}
			}
		}
		cin >> t[i][3];//money
	}
	for(int i=1;i<=k;i++)
	{
		cin >> con[i];
		for(int j=1;j<=n;j++)
		{
			cin >> a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(town[i]==1)
		{
			int money=0;
			for(int j=1;j<=m;j++)
			{
				for(int h=1;h<=2;h++)
				{
					if(t[j][h]==i)
					{
						money=t[j][3];
					}
				}
			}
			sum=sum+money;
		}
		else
		{
			int money[10005],z=1;
			for(int j=1;j<=10003;j++)
			{
				money[i]=0;
			}
			for(int j=1;j<=m;j++)
			{
				for(int h=1;h<=2;h++)
				{
					if(t[j][h]==i)
					{
						if(h==1)
						{
							if(t[j][h]<=t[j][h+1])
							{
								money[z]=t[j][3];
								z++;
							}
						}
						if(h==2)
						{
							if(t[j][h]<=t[j][h-1])
							{
								money[z]=t[j][3];
								z++;
							}
						}
					}
				}
			}
			sort(money+1,money+z);
			for(int j=1;j<town[i];j++)
			{
				cout << money[j] << " ";
				sum=sum+money[j];
			}
		}
	}
	cout << sum;
	return 0;
}	
