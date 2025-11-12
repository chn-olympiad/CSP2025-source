#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int pl=1,a1;
    cin >> a1;
    for (int i=2;i<=n*m;i++)
    {
        int a;
        cin >> a;
        if (a>a1) ++pl;
    }
    int l=int(ceil(pl*1.0/n));
    int h=(l&1)?(pl-1)%n+1:n-(pl-1)%n;
    cout << l << " " << h;
    return 0;
}
