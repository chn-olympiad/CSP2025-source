#include<bits/stdc++.h>

using namespace std;

const int N = 101;
int b[N];

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a,re,n1,m1;
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> b[i];
	}
	a = b[1];
	for(int i = 1;i <= m * n;i++)
	{
		int max = -1;
		for(int k = i;k <= m * n;k++)
		{
			if(b[k] >= max)
			{
				max = b[k];
				re = k;
			}
		}
		swap(b[i],b[re]);
	}
	for(int i = 1;i <= m * n;i++)
	{
		if(b[i] == a)
		{
			re = i;
			break;
		}
	}
	if(re % n == 0) m1 = re / n;
	else m1 = re / n + 1;
	int d = re % n;
	if(m1 % 2 == 0)
	{
		n1 = n + 1 - d;
	}
	else
	{
		if(d == 0) d = n;
		n1 = d;
	}
	cout << m1 << " " << n1;
	
	return 0;
}
