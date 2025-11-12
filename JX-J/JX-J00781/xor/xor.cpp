#include <bits/stdc++.h>
using namespace std;
int n,k,a,cnt,c[5005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin >> n >> k;
	if(k<=1)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> a;
			if(a==k)
			{
				cnt++;
			}
		}
		cout << cnt;
	}
	return 0;
}
