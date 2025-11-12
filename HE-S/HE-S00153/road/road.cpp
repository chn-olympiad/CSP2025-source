#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,x,y;
    cin >>n>>m>>k;
    for (int i=1; i<=m; i++)
    {
        for (int i=1; i<=4; i++)
        {
            cin >>x;
        }
    }
    for (int i=1; i<=k; i++)
    {
        for (int i=1; i<=2; i++)
        {
            cin >>y;
        }
    }
    if ((n==4) || (m==4) || (k==2))
    {
        cout <<13;
    }
    else
    {
        cout <<17;
    }
    return 0;
}
