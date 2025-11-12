#include <bits/stdc++.h>
using namespace std;

long long n,k;
long long num[500005];
long long df[500005];
long long ans;
long long yu;
long long tyu[2000005][2];
long long uo = 0;

long long yi_huo(long long a,long long b)
{
	long long sum = num[a];
	for (int i = a + 1;i <= b;i++)
		sum = sum ^ num[i];
	return sum;
}

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin >> n >> k;
	for (int i = 1;i <= n;i ++)
		cin >> num[i];
	for (int i = 1;i <= n;i++)
	{
		for (int f = 1;f <= i;f++)
		{
			yu = 0;
			if (yi_huo(f,i) == k)
			{
				bool p = 1;
				for (int t = 0;t < uo;t++)
				{
					if (tyu[t][1] <= i && tyu[t][0] >= f)
					{
						//cout << f << " " << i  << " "<< tyu[t][0] << " " << tyu[t][1] << endl; 
						tyu[t][1] = i;
						tyu[t][0] = f;
						p = 0;
						break;
					}else if (tyu[t][1] >= i && tyu[t][0] <= f)
					{
						//cout << f << " " << i << " "<< tyu[t][0] << " " << tyu[t][1] << endl; 
						p = 0;
						break;
					}
				}
				if (p)
				{
					tyu[uo][1] = i;
					tyu[uo][0] = f;
					uo ++;
					yu ++;
				}
			}
			df[f] = df[f] + yu;
		}
	}
	ans = 0;
	for (int i = 1;i <= n;i++)
	{
		if (df[i] >= 1) ans = ans + df[i];
	}	
	cout << ans << endl;
	return 0;
}
