#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,max;
    int a1,a2;
    cin >> n >> m;
    cin >> a1 >> a2;
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=m;j++)
        {
            i*j;
        }
        if(max == n)
        {
            cout << a1;
        }
        else
        {
            cout << a2;
        }
    }
    return 0;
}
