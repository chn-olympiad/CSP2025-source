#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;
PII a[N][3];

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);

    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++ )
            for (int j = 0; j < 3; j ++ )
                scanf("%d", &a[i][j].x), a[i][j].y = j;
        for (int i = 1; i <= n; i ++ )
            sort(a[i], a[i] + 3), reverse(a[i], a[i] + 3);
        int cnt[3] = {0}, ans = 0;
        priority_queue<int, vector<int>, greater<int> > heap[3];
        for (int i = 1; i <= n; i ++ )
        {
            if (cnt[a[i][0].y] < n / 2)
            {
                cnt[a[i][0].y] ++ , ans += a[i][0].x;
                heap[a[i][0].y].push(a[i][0].x - a[i][1].x);
            }
            else if (a[i][0].x - heap[a[i][0].y].top() > a[i][1].x) 
            {
                ans += a[i][0].x - heap[a[i][0].y].top(), heap[a[i][0].y].pop();
                heap[a[i][0].y].push(a[i][0].x - a[i][1].x);
            }
            else 
            {
                ans += a[i][1].x, cnt[a[i][1].y] ++ ;
                heap[a[i][1].y].push(a[i][1].x - a[i][2].x);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}