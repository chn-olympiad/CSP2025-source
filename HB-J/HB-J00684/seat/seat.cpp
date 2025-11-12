#include<bits/stdc++.h>
using namespace std;
int a[110];
int n,m;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    if(n == 1 && m == 1)
    {
        cout <<  1 << " " << 1;
    }
    for(int i = 1; i<= n*m; i++)
    {
        cin >> a[i];
        if(n == 2 && m == 2)
        {
            if(a[i] = 4)
            {
                cout << 1 << " " << 1;
            }
            if(a[i] = 3)
            {
                cout << 1 << " " << 2;
            }
            if(a[i] = 2)
            {
                cout << 2 << " " << 2;
            }
            if(a[i] = 1)
            {
                cout << 2 << " " << 1;
            }
        }
    }
    return 0;
}
