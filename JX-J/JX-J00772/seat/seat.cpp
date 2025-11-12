#include <bits/stdc++.h>

using namespace std;

long long a[1005];
long long n,m,k;

bool cmp(long long a, long long b)
{
    return b < a;
}

int main()
{

    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);

    cin >> n >> m;

    for (int i = 0; i < n * m; i++)
    {
        cin >> a[i];
        if (i == 0)
        {
            k = a[i];
        }
    }


    //cout << k << endl;
    //for (int i = 0; i < n * m; i++) cout << a[i] << ' ';
    //cout << endl;


    sort(a, a + n * m, cmp);


    //for (int i : a) cout << i << ' ';


    for (int i = 0; i < n * m; i++)
    {
        if (a[i] == k)
        {
            //printf("\n a[%d] = %d\n", i, k);
            k = i + 1;   // we should start i with 1, but I make i is 0
            break;
        }
    }
    //cout << k << endl;

    long long ans1 = (k - 1) / n + 1;
    long long ans2;
    if (ans1 % 2 == 0)
    {
        ans2 = n - (k - (ans1 - 1) * n - 1);
    }
    else
    {
        ans2 = k - (ans1 - 1) * n;
    }
    cout << ans1 << ' ' << ans2;

    return 0;

}

/*
3 3
94 95 96 97 98 99 100 93 92

100  95  94
99   96  93
98   97  92



*/
