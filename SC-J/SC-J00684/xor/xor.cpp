# include <iostream>
# include <cstdio>
using namespace std;

int xorsum(int a[], int l, int r)
{
    int s = a[l];
    for (int i = l + 1; i <= r; i++)
    {
        s ^= a[i];
    }
    return s;
}

int main()
{
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

    int n = 0, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (xorsum(a, l, i) == k)
        {
            cnt++;
            l = i + 1;
        }
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
