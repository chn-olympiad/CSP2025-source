#include <bits/stdc++.h>

using namespace std;

struct no
{
    long long x,y;
};

long long n,k,a[500005];
no b[500005];
long long Max = -1;
long long t, s, u;

bool cmp(no a, no b)
{
    return a.x < b.x;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for (int i = 0; i < n ; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
        {
            b[u].x = i;
            b[u].y = i;
            u++;
            continue;
        }
        t = a[i];
        for (int j = i + 1; j < n; j++)
        {
            /*
            if (j == i + 2)
            {
                cout << (t^a[j]) << ' ' << a[j] << endl;
            }*/
            t = (t ^ a[j]);
            if (t == k)
            {
                b[u].x = i;
                b[u].y = j;
                u++;
            }
        }
    }
    sort(b,b+u,cmp);

    s = 0;
    for (int i = 0; i < u; i++)
    {
        if (b[i].y > b[i + 1].x)
            s++;
    }

    cout << u - s;

    return 0;

}
