#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,m,a[101];
    cin >> n >> m;
    for(int i=1; i<=n*m; i++)
    {
        cin >> a[i];
    }
    for(int i=1; i<=n*m; i++)
    {
        if(a[0]>a[i])
        {
            cout << 1 << " " << 1;
        }
    }
    return 0;
}

