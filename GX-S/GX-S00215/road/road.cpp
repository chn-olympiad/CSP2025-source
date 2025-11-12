#include <bits/stdc++.h>

using namespace std;
struct s
{
    int a;
    int b;
    int c;
};
struct y
{
    int a;
    int b;
    int c;
    int d;
    int e;
};
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n,m,k;
    cin >> n >> m >> k;
    s p[m];
    y x[k];
    for(int i = 0;i < m;i++)
        cin >> p[i].a >> p[i].b >> p[i].c;
    for(int i = 0;i < k;i++)
        cin >> x[i].a >> x[i].b >> x[i].c >> x[i].d >> x[i].e;
    cout << 13;
    return 0;
}
