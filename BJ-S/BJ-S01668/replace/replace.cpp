#include <iostream>
#include <queue>
#define ull unsigned long long
using namespace std;

const int N = 2e5 + 10, M = 1e6;
int n, q, l[N], m, ans;
ull s[N][3], p[M], t[3];
string t1, t2;

ull Hash(ull h, int l, int r)
{
    return h % p[r] / p[l - 1];
}
struct Node
{
    int x;
    ull t;
};

void bfs()
{
    queue<Node> q;
    q.push({0, 0});
    while (!q.empty())
    {
        Node u = q.front();q.pop();
        if (u.t == t[2]) ans++;
        if (u.x >= m) continue;
        for (int j = 1; j <= n; j++)
        {
            if (Hash(t[1], u.x, u.x + l[j]) == s[j][1])
            {
                u.t = u.t * p[l[j]] + s[j][1];
                u.x += l[j] + 1;
                q.push(u);
                u.x -= l[j] + 1;
            }
        }
        u.t = u.t * 27 + t1[u.x];
        u.x+=2;
        q.push(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    p[0] = 1;
    for (int i = 1; i <= M; i++) p[i] = p[i - 1] * 27;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++)
            s[i][1] = s[i][1] * 27 + (s1[i] - 'a' + 1);
        for (int i = 0; i < s2.size(); i++)
            s[i][2] = s[i][2] * 27 + (s2[i] - 'a' + 1);
        l[i] = s1.size();
    }
    for (int i = 1; i <= q; i++)
    {
        ans = 0;
        cin >> t1 >> t2;
        m = t1.size();
        t[1] = t[2] = 0;
        for (int i = 0; i < t1.size(); i++)
            t[1] = t[1] * 27 + (t1[i] - 'a' + 1);
        for (int i = 0; i < t2.size(); i++)
            t[2] = t[2] * 27 + (t2[i] - 'a' + 1);
        bfs();
        cout << ans << endl;
    }
    return 0;
}
