#include<bits/stdc++.h>
using namespace std;
string a[100005], b[100005];
struct xy{
    string a, b;
};
vector<xy> v[10005];
int pd(string x, string y)
{
    int cnt = 0;
    for(int i = 0;i < v[x.size()].size();i++)
    {
        if(x == v[x.size()][i].a && y == v[x.size()][i].b) cnt++;
    }
    return cnt;
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    int m, q;
    cin >> m >> q;
    for(int i = 1;i <= m;i++)
    {
        string t1, t2;
        cin >> t1 >> t2;
        v[t1.size()].push_back({t1, t2});
    }
    while(q--)
    {
        int ans = 0;
        string t1, t2;
        cin >> t1 >> t2;
        int n = t1.size();
        if(n != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        for(int i = 0;i <= n;i++)
        {
            if(t1.substr(0, i) != t2.substr(0, i)) break;
            for(int j = n + 1;j > i;j--)
            {
                if(t1.substr(j - 1) != t2.substr(j - 1)) break;
                ans += pd(t1.substr(i, j - i - 1), t2.substr(i, j - i - 1));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
