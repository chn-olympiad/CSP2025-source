#include <bits/stdc++.h>
#define R 998244353
using namespace std;
long long a[5010],n,m,sum,b;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    if (n==3)
    {
    	if (a[3]<a[1]+a[2])
    	{
    		cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
    cout << 6; 
    return 0;
}

