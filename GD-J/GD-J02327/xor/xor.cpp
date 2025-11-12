#include <bits/stdc++.h>
using namespace std;
int n,m,a[50000],sum = 0;
bool vis[50000];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	fill (a,a+1000,0);
	fill (vis,vis+1000,false);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		if (a[i] == m)
		{
			sum++;
			vis[i] = true;
			//cout << i << endl;
		}
	}
	/*if (a[32] == 1 && vis[32])
		cout << "666";*/
	for (int i = 0;i < n-1;i++)
	{
		if (vis[i])
			continue;
		int ce = a[i] xor a[i+1];
		if (ce == m && !vis[i+1])
		{
			cout << i <<"   1   "<<i+1<<endl;
			sum++;
			fill (vis+i,vis+i+1,true);
			continue;
		}
		else if (!vis[i+1])
			for (int j = i+2;j < n;j++)
			{
				if (vis[j])
					break;
				int ce2 = ce xor a[j];
				if (ce2 == m)
				{
					cout << i <<" "<< j << endl;
					/*for (int t = i;t <= j;t++)
					{
						cout << a[t]<<" ";
					}*/
					cout << endl;
					sum++;
					fill (vis+i,vis+i+j,true);
					break;
				}
				else
					ce = ce2;
			}
	}
	/*for (int i = 0;i < n;i++)
	{
		if (vis[i])
		{
			cout << i <<" ";
		}
	}*/
	cout  << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
