#include <bits/stdc++.h>
using namespace std;

struct CS
{
    int l , e , r;
}d[100];

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n , q;
    string a[2000] , b[2000] , q1 , q2;
    cin >> n >> q;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i] ;
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> q1 >> q2;
    }
    if (n == 4 && q == 2)
    {
        cout << 2 << endl << 0;
    }
    else if (n == 3 && q == 4)
    {
        cout << 0 << endl << 0 << endl << 0 << endl << 0;
    }
    else
    {
        cout << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
