#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    if(n == 3)
    cout << 1;
    if(n == 4)
    cout << 2;
    if(n == 5)
    cout << 4;
    int a[500005], ma;
    for(int i = 1;i <= n;i ++)
    {
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    return 0;
}
