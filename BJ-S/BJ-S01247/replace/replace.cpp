#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
const int maxm = 5200005;

char s[maxm], t[maxm];
int chs[maxm][27], cht[maxm][27], fail[maxm], F[maxm], cnt, cnts, cntt;
int seq[maxm << 1], tp, psl[maxn], psr[maxn], L[maxn], R[maxn], qL[maxn], qR[maxn], qsl[maxn], qsr[maxn], ans[maxn];

vector<pair<pii, int> > vec;

void getFail()
{
    queue<int> q;
    for (int i = 0; i <= 26; i++) if (chs[0][i]) fail[chs[0][i]] = 0, F[chs[0][i]] += F[0], q.push(chs[0][i]);
    while (q.size())
    {
        int u = q.front(); q.pop();
        int f = fail[u];
        for (int i = 0; i <= 26; i++)
        {
            if (!chs[u][i]) chs[u][i] = chs[f][i];
            else
            {
                fail[chs[u][i]] = chs[f][i], F[chs[u][i]] += F[chs[f][i]];
                q.push(chs[u][i]);
            }
        }
    }
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);

    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s + 1 >> t + 1; int len = strlen(s + 1);
        L[i] = 1, R[i] = len;
        while (L[i] <= R[i] && s[L[i]] == t[L[i]]) L[i]++;
        if (L[i] > R[i]) continue;
        while (R[i] >= L[i] && s[R[i]] == t[R[i]]) R[i]--;

        int ps = 0, pt = 0;
        for (int j = L[i]; j <= R[i]; j++)
        {
            if (!chs[ps][s[j] - 'a']) chs[ps][s[j] - 'a'] = ++cnts;
            ps = chs[ps][s[j] - 'a'];
            if (!cht[pt][t[j] - 'a']) cht[pt][t[j] - 'a'] = ++cntt;
            pt = cht[pt][t[j] - 'a'];
        }
        psl[i] = tp + 1;
        for (int j = 1; j < L[i]; j++) seq[++tp] = s[j] - 'a'; seq[++tp] = 26;
        for (int j = R[i] + 1; j <= len; j++) seq[++tp] = s[j] - 'a'; psr[i] = tp;
        vec.emplace_back(make_pair(make_pair(ps, pt), -i));
    }

    for (int i = 1; i <= q; i++)
    {
        cin >> s + 1 >> t + 1; int len = strlen(s + 1);
        if (len != strlen(t + 1)) continue;
        int L = 1, R = len;
        while (L <= R && s[L] == t[L]) L++;
        while (R >= L && s[R] == t[R]) R--;
        qL[i] = L, qR[i] = R, qsl[i] = tp + 1;
        for (int j = 1; j < L; j++) seq[++tp] = s[j] - 'a'; seq[++tp] = 26;
        for (int j = R + 1; j <= len; j++) seq[++tp] = s[j] - 'a'; qsr[i] = tp;

        int ps = 0, pt = 0;
        for (int j = L; j <= R; j++)
        {
            if (!chs[ps][s[j] - 'a']) { ps = -1; break; }
            ps = chs[ps][s[j] - 'a'];
            if (!cht[pt][t[j] - 'a']) { pt = -1; break; }
            pt = cht[pt][t[j] - 'a'];
        }
        if (~ps && ~pt) vec.emplace_back(make_pair(make_pair(ps, pt), i));
    }
    for (int i = 0; i <= cnts; i++) for (int j = 0; j < 26; j++) chs[i][j] = 0;

    sort(vec.begin(), vec.end()); int l = 0;
    while (l < vec.size())
    {
        int r = l; while (r + 1 < vec.size() && vec[r + 1].first == vec[l].first) r++;
        if (vec[l].second < 0 && vec[r].second > 0)
        {
            for (int i = l; i <= r; i++)
                if (vec[i].second < 0)
                {
                    int id = -vec[i].second, p = 0;
                    for (int j = psl[id]; j <= psr[id]; j++)
                    {
                        if (!chs[p][seq[j]]) chs[p][seq[j]] = ++cnt;
                        p = chs[p][seq[j]];
                    }
                    F[p]++;
                }
            getFail();
            for (int i = l; i <= r; i++)
                if (vec[i].second > 0)
                {
                    int id = vec[i].second, p = 0;
                    for (int j = qsl[id]; j <= qsr[id]; j++)
                    {
                        p = chs[p][seq[j]];
                        ans[id] += F[p];
                    }
                }
            for (int i = 0; i <= cnt; i++)
            {
                F[i] = fail[i] = 0;
                for (int j = 0; j <= 26; j++) chs[i][j] = 0;
            }
            cnt = 0;
        }
        l = r + 1;
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << "\n";
    return 0;
}