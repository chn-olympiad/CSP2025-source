#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    cin.tie(0), cout.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> scores(n * m);
    for (int i = 0; i < n * m; i++)
    {
        cin >> scores[i].first;
        scores[i].second = i;
    }
    sort(scores.begin(), scores.end(), [](pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    });
    bool iszheng = true;
    for (int raw = 0; raw < n * m; raw++)
    {
        if (scores[raw].second == 0)
        {
            cout << raw / n + 1 << ' ' << (raw / n % 2 == 0 ? raw % n : (n - raw % n - 1)) + 1;
            break;
        }
    }
    cout << endl;
    fclose(stdin), fclose(stdout);
    return 0;
}
