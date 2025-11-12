#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10, M = 5e6 + 10, Base = 131, mod = 998244353;

struct String
{
    int hl, hr;
    PII hm;
} s[N];
int n, Q, tot;
char str1[M], str2[M];
map<PII, vector<String> > mp;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);

    scanf("%d%d", &n, &Q);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%s%s", str1 + 1, str2 + 1);
        int len = strlen(str1 + 1), av = 0, iv = len + 1;
        for (int j = 1; j <= len; j ++ )
            if (str1[j] != str2[j])
                av = max(av, j), iv = min(iv, j);
        if (av == 0) continue;
        int hash = 0;
        for (int j = iv - 1; j; j -- )
            hash = ((LL)hash * Base + str1[j] - 'a' + 1) % mod;
        s[++ tot].hl = hash, hash = 0;
        for (int j = av + 1; j <= len; j ++ )
            hash = ((LL)hash * Base + str2[j] - 'a' + 1) % mod;
        s[tot].hr = hash, hash = 0;
        for (int j = iv; j <= av; j ++ )
            hash = ((LL)hash * Base + str1[j] - 'a' + 1) % mod;
        s[tot].hm.x = hash;
        for (int j = iv; j <= av; j ++ )
            hash = ((LL)hash * Base + str2[j] - 'a' + 1) % mod;
        s[tot].hm.y = hash;
        mp[s[tot].hm].push_back(s[tot]);
    }
    while (Q -- )
    {
        scanf("%s%s", str1 + 1, str2 + 1);
        int lenn = strlen(str2 + 1);
        int len = strlen(str1 + 1);
        if (lenn != len)
        {
            puts("0");
            continue;
        }
        int av = 0, iv = len + 1;
        for (int j = 1; j <= len; j ++ )
            if (str1[j] != str2[j])
                av = max(av, j), iv = min(iv, j);
        PII nd;
        int hash = 0;
        for (int i = iv; i <= av; i ++ )
            hash = ((LL)hash * Base + str1[i] - 'a' + 1) % mod;
        nd.x = hash;
        for (int i = iv; i <= av; i ++ )
            hash = ((LL)hash * Base + str2[i] - 'a' + 1) % mod;
        nd.y = hash;
        unordered_set<int> s1, s2;
        s1.insert(0), s2.insert(0), hash = 0;
        for (int j = iv - 1; j; j -- )
            hash = ((LL)hash * Base + str1[j] - 'a' + 1) % mod, s1.insert(hash);
        hash = 0;
        for (int j = av + 1; j <= len; j ++ )
            hash = ((LL)hash * Base + str2[j] - 'a' + 1) % mod, s2.insert(hash);
        int ans = 0;
        for (auto it : mp[nd])
            if (s1.count(it.hl) && s2.count(it.hr)) 
                ans ++ ;
        printf("%d\n", ans);
    }

    return 0;
}