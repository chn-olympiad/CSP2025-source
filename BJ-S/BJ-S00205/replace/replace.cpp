# include <iostream>
using namespace std;

const int MAXN = 2e5 + 7;
struct Node
{
    int cur1, cur2;
    int x;
    int l;
}tsl[MAXN];

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int cur1, cur2;
        int x;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'b')
                cur1 = i;
            if (s2[i] == 'b')
                cur2 = i;
        }
        tsl[i].cur1 = cur1;
        tsl[i].cur2 = cur2;
        tsl[i].x = cur1 - cur2;
        tsl[i].l = s1.size();
    }
    while (q--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (s1.size() != s2.size())
        {
            cout << 0 << endl;
            continue;
        }
        int ncur1, ncur2;
        int nx;
        int l2 = s1.size();

        int cur1, cur2;
        int x;
        int l1;
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == 'b')
                ncur1 = i;
            if (s2[i] == 'b')
                ncur2 = i;
        }
        nx = ncur1 - ncur2;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            x = tsl[i].x;
            cur1 = tsl[i].cur1;
            cur2 = tsl[i].cur2;
            l1 = tsl[i].l;
            if (nx == x && ncur1 > cur1 && l2-ncur1 > l1-cur1)
                cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}
