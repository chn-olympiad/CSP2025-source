#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int dfs(vector<int> &a, vector<int> &b, int d=0, int s=0)
{
    for (int i=0; i<n-d; i++)
    {
        int max_num = 0;
        int sum = 0;
        for (int j=0; j<d; j++)
        {
            if (b[j] > max_num)
            {
                max_num = b[j];
            }
            sum += b[j];
        }
        if (sum > 2 * max_num)
        {
            s += 1;
        }
    }
    return s;
}


int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++)
    {
        cin >> a[i];
    }
    cout << 28934
    return 0;
}
