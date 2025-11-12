#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)
{
	return a > b;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],stur;
	cin >> n >> m;
	cin >> stur;
	a[1] = stur;
	for(int i = 2;i <= n * m;i++)
		cin >> a[i];
	sort(a + 1,a + n * m + 1,cmp);
	int count = 1;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 1;j <= n;j++)
		{
			if(a[count] == stur)
			{
				if(i % 2 == 1)
					cout << i <<" "<< j;
				else
					cout << i <<" "<< n - j + 1;
				return 0;
			}
			count++;
		}
	}
	return 0;
}
