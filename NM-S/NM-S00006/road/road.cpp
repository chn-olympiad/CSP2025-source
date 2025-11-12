#include <bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
}a[100005];
int d[500][500];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= m+1; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
        for(int j = m; j <= m+k+1; i++)
        {
            cin >> d[i][j];
        }
    }
    return 0;
}
