#include <iostream>
#include <cstdio>
using namespace std;
int n, k, a[500001], ans;
int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int end = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int sum;
            for (int k = i; k <= j - 1; k++)
            {
                sum += a[i] ^ a[i + 1];
            }
	    if (sum == k && i < end)
	    {
	    	ans++;
	    	end = j;	
	    }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
