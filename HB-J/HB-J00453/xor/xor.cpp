#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("xor.in" , "r" , stdin);
    freopen("xor.out" , "w" , stdout);
    int n , k;
    cin >> n >> k;
    int a[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0 , sum;
    int j;
    for(int i = 1; i <= n; i++)
    {
        sum = 0;
        for(j = i; j <= n; j++)
        {
            sum = sum ^ a[j];
            if(sum == k)
            {
                ans++;
                i = j;
                break;
            }
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
