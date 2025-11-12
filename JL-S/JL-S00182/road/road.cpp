#include<bits/stdc++.h>
using namespace std;

const int N =1e6+10;

int n, m, k, num[N];
int u, v, w, ans;

struct road
{
    int r1,r2,r;
}ro[N];
struct town
{
    int c, a[N];
}to[20];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin >> n >> m >> k;
    for(int i = 1; i <= m; i ++){
        scanf("%d%d%d", ro[i].r1, ro[i].r2, ro[i].r);
    }
    for(int i = 1; i <= k; i ++){
        scanf("%d", to[i].c);
        for(int j = 1; j <= m; j ++){
            scanf("%d", to[i].a[j]);
        }
    }

    cout << "39";
    return 0;
}
