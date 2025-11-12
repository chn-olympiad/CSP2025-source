#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    freopen("seatin","r",stdin);
    freopen("seatout","W",stdout);
    ll n,m;
    cin >> n >> m;
    ll a[n*m];
    ll R;
    for(int i=0;i<n*m;i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<n*m;i++)
    {
        R=a[0];
        sort(a[0],a[i+1]);
        if(R=a[i])
        {
            if(i<=n)
            {
                cout << "1" << i;
            }
            if(i>n)
            {
                cout << i/m << i%m;
            }
        }
    }
    return 0;
}
