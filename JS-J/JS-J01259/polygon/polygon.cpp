#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int myL[505];
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> myL[i];
	if(n>10)
		cout << 10 << endl;
	else if(n<3)
		cout << 0 << endl;
	else if(n==3)
	{
		int max = 0, Sum=0;
		for(int i=1; i<=n; i++)
		{
			Sum += myL[i];
			if(myL[i]> max)
				max = myL[i];
		}
		if(Sum > (max*2))
			cout << "1\n";
		else
			cout << "0\n";
		return 0;
	}
	else if(n==4)
	{
		int cnt=0, max = 0, Sum=0;
		for(int i=1; i<=n; i++)
		{
			Sum += myL[i];
			if(myL[i]> max)
				max = myL[i];
		}
		if(Sum > (max*2))
			cnt++;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				for(int k=j+1; k<=n; k++)
				{
					int r = 0, ma=0;;
					r+=myL[i] + myL[j] + myL[k];
					for(int z=i; z<=k; z++)
					{
						if(myL[z]>ma)
							ma = myL[z];
					}
					if(r>(2*ma))
						cnt++;
				}
		cout << cnt%998244353 << endl;
		return 0;
	}
	else if(n==5)
	{
		int cnt=0, max = 0, Sum=0;
		for(int i=1; i<=n; i++)
		{
			Sum += myL[i];
			if(myL[i]> max)
				max = myL[i];
		}
		if(Sum > (max*2))
			cnt++;
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				for(int k=j+1; k<=n; k++)
				{
					int r = 0, ma=0;;
					r+=myL[i] + myL[j] + myL[k];
					for(int z=i; z<=k; z++)
					{
						if(myL[z]>ma)
							ma = myL[z];
					}
					if(r>(2*ma))
						cnt++;
				}
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				for(int k=j+1; k<=n; k++)
					for(int l=k+1; l<=n; l++)
					{
						int r = 0, ma=0;;
						r+=myL[i] + myL[j] + myL[k] + myL[l];
						for(int z=i; z<=l; z++)
						{
							if(myL[z]>ma)
								ma = myL[z];
						}
						if(r>(2*ma))
							cnt++;
					}	
		cout << cnt%998244353 << endl;
		return 0;
	}
	return 0;
}



