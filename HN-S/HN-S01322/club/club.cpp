#include<bits/stdc++.h>
using namespace std;
long long v,n,a[105][4],people,b[105],c[4],maxx,t,sum[105],u=0,num=0,st=0,symbol;
int main()
{
	freopen("club","r",stdin);
	freopen("club","w",stdout);
	cin >> v >> n;
	people = n/2;
	
	for(int k=1;k<=v;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				
				cin >> a[i][j];
				if(a[i][2] == 0 && a[i][3] == 0)
				{
					u++;
				}
				if(a[i][2] == 0)
				{
					st++;
				}
			}
		}
		if(u == n*2)
		{
			symbol=1;
			for(int ii=1;ii<=n;ii++)
			{
				for(int jj=ii;jj<=n;jj++)
				{
					if(a[ii] < a[jj])
					{
						swap(a[ii],a[jj]);
					}
				}
			}
			for(int i=1;i<=n/2;i++)
			{
				cout << a[i];
			}
		}
		else if(st == n)
		{
			symbol = 2;
			for(int i=1;i<=n;i++)
			{
				if(a[i][2] > a[i][1] && c[2] <= people)
				{
					t=2;
					sum[2]+=a[i][2];
				}
				else
				{
					sum[1]+=a[i][1];
				}
			}
			sum[1] += sum[2];
			
		}
	}
	if(symbol == 1)
	{
		cout << symbol << " ";
		cout << num;
	}
	else if(symbol == 2)
	{
		cout << symbol << " ";
		cout << sum[1];
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			cout << sum[i];
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
