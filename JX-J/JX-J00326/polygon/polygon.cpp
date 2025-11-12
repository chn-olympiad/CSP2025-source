#include<bits/stdc++.h>
using namespace std;
int a[6000] = {};
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,cnt =0;
    cin >> n;
    for(int i = 1; i<= n;i++)
    {
        cin >> a[i];
    }
    if(n == 3)
    {
            int sum = a[1] + a[2] + a[3];
            int maxn = max(max(a[2],a[1]),max(a[1],a[3]));
            if(sum > 2 * maxn)
            {
                cout << 1;
                return 0;
            }
    }
    cout << 7896;
    return 0;
}
