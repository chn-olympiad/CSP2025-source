#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
int a[N];
int n,sum,m;
int main()
{
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1; i<= n;i++)
    {
        cin >> a[i];
        if(a[i] > 2 * n && m >= 3)
        {
            sum += a[i];
            if(a[i] > sum)
            {
                max(a[i]);
                sum = max(a[i]); / m;
            }
        }
        if(a[i] > 1e7)
        {
            cout << a[i] % 998244353;
        }
        break;
    }
    cout << sum;
	return 0;
}
