#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int a[N];
int k,sum;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> k;
	for(int i = 1;i <= k;i++)
    {
        cin >> a[i];
        if(a[i] <= k && a[i] >= k)
        {
            sum = sort(a[i],a[i] + 1);
            if(num >= a[i])
            {
                a[i] - a[k];
                a[k] - a[i];
                a[k - 1] - a[i - 1];
                sum += a[k];
            }
            break;
        }
    }
    cout << sum;
	return 0;
}
