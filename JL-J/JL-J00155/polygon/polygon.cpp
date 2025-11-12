#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >>n;
    int maxn = 0;
    int sum = 0;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        maxn = i;
        sum += i;
        if(i >= 3 && 2 * maxn < sum)
        {
            cnt++;
        }
    }
    cout << cnt;


    return 0;
}
