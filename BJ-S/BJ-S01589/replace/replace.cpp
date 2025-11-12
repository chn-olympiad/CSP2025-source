#include <bits/stdc++.h>
using namespace std;
#define For(i, x, y) for (int i = x; i <= y; i++)
#define foR(i, x, y) for (int i = x; i >= y; i--)
#define vector basic_string
typedef pair<int, int> pii;
typedef unsigned long long ull;
const int N = 2e5 + 5, M = 1e7 + 5, base = 73;
int n, Q;
char s[2][M];
struct node
{
    int lenl, lenr;
    ull hl, hr;
};
vector<node> a[N];

int root = 1, trie[M][26], id[M], tot = 1, idcnt;
ull Hl[M], Hr[M];

void insert(int I)
{
    int m = strlen(s[0] + 1);
    int u = root;
    int l = -1, r = -1;
    For (i, 1, m)
        if (s[0][i] != s[1][i])
        {
            l = i;
            break;
        }
    foR (i, m, 1)
        if (s[0][i] != s[1][i])
        {
            r = i;
            break;
        }
    For (k, 0, 1)
        For (i, l, r)
        {
            int d = s[k][i] - 'a';
            if (!trie[u][d])
                trie[u][d] = ++tot;
            u = trie[u][d];
        }
    if (!id[u])
        id[u] = ++idcnt;
    node res = {l - 1, m - r, 0, 0};
    foR (i, l - 1, 1)
        res.hl = res.hl * base + (s[0][i] - 'a' + 1);
    For (i, r + 1, m)
        res.hr = res.hr * base + (s[0][i] - 'a' + 1);
    a[id[u]] += res;
}

void cal()
{
    int m = strlen(s[0] + 1);
    if (m != strlen(s[1] + 1))
    {
        puts("0");
        return;
    }
    int u = root;
    int l = -1, r = -1;
    For (i, 1, m)
        if (s[0][i] != s[1][i])
        {
            l = i;
            break;
        }
    if (l == -1)
    {
        puts("0");
        return;
    }
    foR (i, m, 1)
        if (s[0][i] != s[1][i])
        {
            r = i;
            break;
        }
    For (k, 0, 1)
        For (i, l, r)
        {
            int d = s[k][i] - 'a';
            u = trie[u][d];
        }
    if (!id[u])
    {
        puts("0");
        return;
    }
    foR (i, l - 1, 1)
        Hl[l - i] = Hl[l - i - 1] * base + (s[0][i] - 'a' + 1);
    For (i, r + 1, m)
        Hr[i - r] = Hr[i - r - 1] * base + (s[0][i] - 'a' + 1);
    int res = 0;
    for (auto i : a[id[u]])
    {
        if (i.lenl <= l - 1 && i.lenr <= m - r && i.hl == Hl[i.lenl] && i.hr == Hr[i.lenr])
            res++;//, cout << i.lenl << endl;
    }
    printf("%d\n", res);
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> Q;
    For (i, 1, n)
    {
        scanf("%s%s", s[0] + 1, s[1] + 1);
        insert(i);
    }
    while (Q--)
    {
        scanf("%s%s", s[0] + 1, s[1] + 1);
        cal();
    }
    return 0;
}