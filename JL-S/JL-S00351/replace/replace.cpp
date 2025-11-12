#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
//#include <unordered_map>

using namespace std;

typedef unsigned long long LL;

const int N = 200010, M = 10000010, K = 10000010;

int n, q;
char s[M], t[M];
int tr[M][27], idx, cnt[M];
map<pair<LL, LL>, int> mp;
LL hash_table[K], val_table[K];
//unordered_map<LL, LL> mp2;
LL p[M], h[M];

inline int find(LL x)
{
    int pos = (x % (M - 1) + M - 1) % (M - 1);
    //cout << pos << endl;
    while (hash_table[pos] != x && hash_table[pos] != -1) pos = (pos + 1) % (M - 1);//cout << pos << endl;
    //cout << x << ' ' << pos << ' ' << hash_table[pos] << endl;
    return pos;
}

void insert(int root)
{
    int p = root;
    for (int i = 1; s[i]; i ++ )
    {
        int c = s[i] - 'a';
        if (!tr[p][c]) tr[p][c] = ++ idx;
        p = tr[p][c];
    }
    cnt[p] ++ ;
}

void dfs(int u, LL val)
{
    int x = find(val);
    hash_table[x] = val, val_table[x] = cnt[u];//cout << x << ' ' << val << endl;
    //cout << u << ' ' << cnt[u] << ' ' << val << endl;
    for (int i = 0; i < 27; i ++ )
    {
        int j = tr[u][i];
        if (j)
        {
            cnt[j] += cnt[u];
            dfs(j, val * 13331 + i + 'a');
        }
    }
}

inline LL get_hash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    scanf("%d%d", &n, &q);
    for (int i = 0; i < K; i ++ ) hash_table[i] = -1;
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%s%s", s + 1, t + 1);
        int pos1 = 1, pos2 = strlen(s + 1);
        while (pos1 <= pos2 && s[pos1] == t[pos1]) pos1 ++ ;
        while (pos1 <= pos2 && s[pos2] == t[pos2]) pos2 -- ;
        LL val1 = 0, val2 = 0;
        for (int i = pos1; i <= pos2; i ++ )
        {
            val1 = val1 * 13331 + s[i];
            val2 = val2 * 13331 + t[i];
            s[i] = 'z' + 1;
        }
        //for (int i = 1; i <= strlen(s + 1); i ++ ) cout << s[i];cout << endl;
        if (!mp.count({val1, val2})) mp[{val1, val2}] = ++ idx;
        insert(mp[{val1, val2}]);
    }
    
    for (auto t : mp) dfs(t.second, t.first.first * 13331 + t.first.second);
    
    while (q -- )
    {
        scanf("%s%s", s + 1, t + 1);
        int pos1 = 1, pos2 = strlen(s + 1);
        while (pos1 <= pos2 && s[pos1] == t[pos1]) pos1 ++ ;
        while (pos1 <= pos2 && s[pos2] == t[pos2]) pos2 -- ;
        LL val1 = 0, val2 = 0;
        for (int i = pos1; i <= pos2; i ++ )
        {
            val1 = val1 * 13331 + s[i];
            val2 = val2 * 13331 + t[i];
            s[i] = 'z' + 1;
        }
        p[0] = 1, h[0] = 0;
        for (int i = 1; i <= strlen(s + 1); i ++ )
        {
            p[i] = p[i - 1] * 13331;
            h[i] = h[i - 1] * 13331 + s[i];
        }
        if (!mp.count({val1, val2})) puts("0");
        else
        {
            int root = mp[{val1, val2}], ans = 0;
            for (int i = 1; i <= strlen(s + 1); i ++ )
            {
                int l = i, r = strlen(s + 1);
                while (l < r)
                {
                    int mid = l + r + 1 >> 1;
                    //cout << (val1 * 13331 + val2) * p[mid - i + 1] + get_hash(i, mid) << endl;
                    if (hash_table[find((val1 * 13331 + val2) * p[mid - i + 1] + get_hash(i, mid))] != -1) l = mid;
                    else r = mid - 1;
                }
                //cout << i << ' ' << r << ' ' << get_hash(i, r) + (val1 * 13331 + val2) * p[r - i + 1] << ' ' << s[3] << ' ' << s[4] << endl;
                //cout << i << ' ' << r << endl;
                if (hash_table[find((val1 * 13331 + val2) * p[r - i + 1] + get_hash(i, r))] != -1)
                    ans += val_table[find((val1 * 13331 + val2) * p[r - i + 1] + get_hash(i, r))];
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}