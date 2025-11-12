#include<bits/stdc++.h>
#define endl '\n'
#define LX long long
using namespace std;
vector<LX> a(500005,0);
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	LX n, k, sum = 0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int k=1;k<=n;k++)
	{
		LX s = 0;
		for(int i=k;i<=n;i++)
		{
			int x = a[i];
			if(x == k)
			{
				s++;
				i++;
			}
			for(int j=i+1;j<=n;j++)
			{
				x^=a[j];
				if(x == k)
				{
					i = j + 1;
					s++;
					break;
				}
			}
		}
		sum = max(s,sum);
	} 
	cout << sum << endl;	
	return 0;
}
