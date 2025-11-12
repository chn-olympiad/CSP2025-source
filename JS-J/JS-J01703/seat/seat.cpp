#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


typedef struct xy
{
    int x_n;
    int y_n;
}XY;


XY dfs_search(vector<int> &a, int d, int n, int m, int s=0, int e=-1)
{
    if (e == -1)
    {
        e = int(a.size()) - 1;
    }
    if (s == e || a[s] == d)
    {
        //cout << "debug: " << s << " " << e << " " << n << " " << m << endl;
        XY t;
        t.x_n = (m * n - s - 1) / m;
        t.y_n = (m * n - s - 1) % m;
        if (t.x_n % 2)
        {
            t.y_n = m - t.y_n - 1;
        }
        return t;
    }
    if (a[(s+e)/2]>d)
    {
        return dfs_search(a, d, n, m, s, (s+e)/2);
    }
    return dfs_search(a, d, n, m, (s+e)/2, e);
}


int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n*m);
    for (int i=0; i<n*m; i++)
    {
        cin >> a[i];
    }
    int tmp_n = a[0];
    sort(a.begin(), a.end());
    XY temp = dfs_search(a, tmp_n, n, m);
    cout << temp.x_n + 1 << " " << temp.y_n + 1;
    return 0;
}
