#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[110];
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n>>m>>a[1];
    int s = a[1];
    for(int i = 2; i<=n*m;i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n*m + 1,cmp);
    int l = 1, rm = m* n, mid;
    while(l <= rm){
        mid = (l + rm)/2;
        if(a[mid] > s)l = mid+ 1;
        else rm = mid-1;
    }
    int cnt1 = (l - 1)%n + 1, c = (l+m - 1)/m;
    int r = (c %2? cnt1: n - cnt1 + 1);
    cout << c <<' '<< r;
    return 0;
}
