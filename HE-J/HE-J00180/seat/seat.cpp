#include<bits/stdc++.h>

using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sum = 0;
	cin>>n>>m;
	int a[n * m + 5];
	for(int i = 1; i <= n * m; i++)
	{
		cin>>a[i];
	}
	int o = a[1],b;
	sort(a + 1, a + n * m + 1, cmp);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == o)
		{
			b = i;
		}
	}
	if(b <= n)
	{
		cout<<1<<" "<<b; 
	}else
	{
		while(b - n >= 0)
		{
			b -= n;
			sum++;
		}
		if(b == 0)
		{
			if(sum % 2 == 0)
			{
				cout<<sum<<" "<<1;
			}else
			{
				cout<<sum<<" "<<n;
			}
		}else
		{
			if(sum % 2 != 0)
			{
				cout<<sum + 1<<" "<<n - b + 1; 
			}else
			{
				cout<<sum + 1<<" "<<b;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
