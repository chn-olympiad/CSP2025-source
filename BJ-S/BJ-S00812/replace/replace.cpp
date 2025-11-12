#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int q;
    cin>>q;
    for(int i = 1; i <= q; i++)
    {
        cout << 2*(q-i)-1 << endl;
    }
    return 0;
}
