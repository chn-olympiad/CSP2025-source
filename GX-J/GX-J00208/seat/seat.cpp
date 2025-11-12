#include <bits/stdc++.h>
using namespace std;

int a[114];
int n,m;

bool cmp(int x,int y){return x>y;}
int DNIF(int x)
{
    for (int i = 1;i <= n*m;i++)
        if (a[i] == x) return i;
    return -1;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1;i <= n*m;i++)
        cin >> a[i];

    int r = a[1];
    sort(a+1,a+m*n+1,cmp);
    int c = DNIF(r);
    int rl = c/n + 1;
    int rh = c % n;
    if (rh == 0)
        rl--;
    if (rl % 2 == 0)
    {
        rh = n - rh + 1;
    }
    else rh+=2;

    cout << rl <<' '<< rh;
    return 0;
}
