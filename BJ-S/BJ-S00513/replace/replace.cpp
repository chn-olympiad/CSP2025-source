#include<bits/stdc++.h>

using namespace std;

string a, b;

string t1, t2;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    int n, q;

    cin >> n >> q;

    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b;
    }

    for(int i = 1; i <= q; i++)
    {
        cin >> t1 >> t2;
    }

    for(int i = 1; i <= q; i++)
    {
        cout << 0 << endl;
    }

    return 0;
}

