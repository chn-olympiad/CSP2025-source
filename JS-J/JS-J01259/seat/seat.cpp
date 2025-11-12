#include <bits/stdc++.h>
using namespace std;


int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int  ScoRe[110];
	int n,m;
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >>ScoRe[i];
	}
	int R = ScoRe[1];
	for(int i=1; i<n*m; i++)
		for(int j=i+1; j<=n*m; j++)
		{
			if(ScoRe[j]>ScoRe[i])
				swap(ScoRe[i], ScoRe[j]);
		}
	int PM;
	for(int i=1; i<=n*m; i++)
	{
		if(ScoRe[i] == R)
			PM = i;
	}
	//main
	int i=1, j=1,k=1;
	while(1)
	{
		if(j%2 == 1)
		{
			if(i==n)
			{
				j++;
			}
			else
			{
				i++;
			}
		}
		else if(j%2==0)
		{
			if(i==1)
			{
				j++;
			}
			else
			{
				i--;
			}
		}
		k++;
		if(k == PM)
		{
			cout << j << " " << i << endl;
			break;
		}
	}
	return 0;
}
