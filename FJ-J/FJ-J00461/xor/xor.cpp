#include <bits/stdc++.h>
#define ll long long
#define MAXN 500005
using namespace std;
ll n,a[MAXN],k,sum,cnt,ans,pos;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;//1 -> 1 3 -> 11  1^3 -> 1 ^ 11 -> 10
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	for(int i = 1 ; i <= n ; i++)
	{
		int pos = i;
		//cout << "-----" << i << "-----\n";
		for(int j = pos ; j <= n ; j++)
		{
			if(pos == j)
			{
				sum += a[j];
				if(sum == k)
				{
					//cout << j << "<--j=pos\n";
					cnt++;
					sum = 0;
					pos = j + 1;
				}
			}
			else
			{
				if((sum ^ a[j]) == k)
				{
					//cout << pos << "->" << j << "<--sum=k " << (sum ^ a[j]) << " " << k << " \n";
					cnt++;
					sum = 0;
					pos = j + 1;
				}
				else
				{
					sum ^= a[j];
				}
			}
		}
		ans = max(ans,cnt);
		cnt = 0;
	}
	cout << ans;
	return 0;
}
