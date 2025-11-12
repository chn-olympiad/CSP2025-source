#include <bits/stdc++.h>
using namespace std;
int n,a[100000];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++)
    {
        cin >>a[i];
    }
    long long cnt = 0;
    for(int i= 1;i<=n-2;i++)
    {
        cnt+=i;
    }
    cout << cnt;
    return 0;
}
