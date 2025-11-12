#include <bits/stdc++.h>
using namespace std;
long long a[500010],R,n,m,k;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<=n;i++)
    {
        if (!a[i])
        {
        	m++;
		}
		else
		{
			if (a[i+1]==1)
			{
				m++;
				i++;
			}
		}
    }
    cout << m;
    return 0;
}

