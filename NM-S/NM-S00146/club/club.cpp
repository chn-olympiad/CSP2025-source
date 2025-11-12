#include<bits/stdc++.h>
using namespace std;

#define N 3
int t,a[N],ans,c;
int n=n*2;
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int i = 1; i <= t; ++i)
    {
        cin >> n;
        for(int j = 1; j <= n; ++j)
        {
            cin >> a[i];
            if(a[i])
                c = a[i];
        }

    }
    ans += c;
    cout << ans << endl;

    return 0;
}
