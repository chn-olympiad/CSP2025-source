#include <bits/stdc++.h>
using namespace std;
int n, m, pos = 1;
int ans[15][15];
struct Student {
    int id, mark;
}a[10086];
bool cmp(Student x, Student y)
{
    return x.mark > y.mark;
}
int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin >> n >> m;
    int len = n * m;
    for (int i = 1; i <= len; i ++)
    {
        a[i].id = i;
        cin >> a[i].mark;
    }
    sort(a + 1, a + len + 1, cmp);
    for (int j = 1; j <= m; j ++)
    {
        if(j % 2 == 1)
        {
            for (int i = 1; i <= n; i ++)
            {
                ans[i][j] = a[pos].mark;
                if(a[pos].id == 1)
                {
                    cout << j << " " << i;
                    return 0;
                }
                pos ++;
            }
        }
        else if(j % 2 == 0)
        {
            for (int i = n; i >= 1; i --)
            {
                ans[i][j] = a[pos].mark;
                if(a[pos].id == 1)
                {
                    cout << j << " " << i;
                    return 0;
                }
                pos ++;
            }
        }
    }
    return 0;
}
