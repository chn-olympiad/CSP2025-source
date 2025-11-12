#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	int x,y;
	cin>>n>>m;
	int b[n*m];
	for(int i = 1;i <= n*m;i++)
	{
		cin>>b[i];
	}
	int sum = b[1];
	for(int i = 1;i <= n*m;i++)
	{
		if(b[i+1] > b[i])
		{
			swap(b[i],b[i+1]);
		}
	}
	for(int i = 1;i <= n*m;i++)
	{
		if(b[i] == sum)
		{
			if((i / n + 1) % 2 != 0)
			{
				x = i / n + 1;
				y = m - i % m - 1;
			}
			else
			{
				x = i / n + 1;
			    y = m - i % m + 1;
			}
			break;
		}
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
