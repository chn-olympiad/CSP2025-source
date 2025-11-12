#include <bits/stdc++.h>
using namespace std;
int qian[500005];
int yh(int a,int b)
{
	int te = 1,ans = 0;
	while (max(a,b))
	{
		if (a & 1)
		{
			if (!(b & 1))
				ans += te;
			
		}	
		else
		{
			ans += (b & 1) *te;
		}
		te *= 2;
		a /= 2;
		b /= 2;
	}
	return ans;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k,temp;
	cin >> n >> k;
	cin >> qian[1];
	for (int i = 2;i <= n;i++)
	{
		cin >> temp;
		qian[i] = qian[i-1] ^ temp; 
	}
//	for (int i = 1;i <= n;i++)
//		cout << qian[i] << ' ';
	long long jl = 1,sum = 0;
	for (int i = 1;i <= n;i++)
	{
		for (int j = jl;j <= i;j++)
		{
 			if (j == 1)
			{
				if (qian[i] == k)
				{
					sum++;
					jl = 2;
					break;
				}
			}
			else
			{
				if (yh(qian[i],qian[j-1]) == k)
				{
					sum++;
					jl = j+1;
					break;
				}
			}
			
		} 
	}
	cout << sum;
	return 0;
} 
