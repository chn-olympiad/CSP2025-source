# include <iostream>
# include <vector>
# include <algorithm>
# include <cstdio>
using namespace std;

bool polygon(vector<int> a, int l, int r)
{
    int amaxi = max_element(a.begin() + l, a.begin() + r) - a.begin();
    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (i != amaxi)
        {
            sum += a[i];
        }
    }
    return sum > 2 * amaxi;
}


int main()
{
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);

    int n = 0;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    int l = 0, r = 2, cnt = 0;
    while (r <= n - 1)
    {
        for (int i = l; i + 2 <= r; i++)
        {
            if (polygon(a, l, r))
            {
                cnt++;
            }
        }
        r++;
    }
    cout << cnt;

    fclose(stdin);
    fclose(stdout);
    return EXIT_SUCCESS;
}