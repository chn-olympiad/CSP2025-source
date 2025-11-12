#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define y1 Goodbye_1
#define y2 Goodbye_2
#define ll long long
#define o1 first
#define o2 second
#define omp make_pair
#define opb push_back
#define inf 3423423423423423422ll
#define MAX_N 222222
#define MAX_L 5222222

using namespace std;

ll read(){ll x = 0;char c = 0;bool v = false;do{c = getchar();if(c == '-')v = true;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');return v ? -x : x;}
char gtc(){char c = 0;while(c <= ' ' && c != EOF)c = getchar();return c;}

// MAX_L + 4 * MAX_N

template<size_t N, int atoz> // atoz = 27
struct Trie2
{
    int n, s[N][atoz], f[N], rel[N];
    int insert(char* c)
    {
        int u = 0;
        for( ; *c; c++)
        {
            int z = *c - 'a';
            if(!s[u][z])
                s[u][z] = ++n, f[n] = u;
            u = s[u][z];
        }
        return u;
    }

    int queryid(char* c)
    {
        int u = 0;
        for( ; *c; c++)
        {
            int z = *c - 'a';
            if(!s[u][z])
                return u;
            u = s[u][z];
        }
        return u;
    }

    int querysum(int t)
    {
        int ans = 0;
        for(int i = t; i; i = f[i])
            ans += rel[i];
        return ans;
    }
};

template<size_t N, int atoz> // atoz = 27, '{'
struct Trie1
{
    Trie2<N, atoz> t2;
    int n, s[N][atoz];
    vector<int> t2id[N];
    vector<pair<int, int> > qs[N]; // id in t2, query id
    int ans[N];
    void insert(char* c1, char* c2)
    {
        int u = 0;
        for( ; *c1; c1++)
        {
            int z = *c1 - 'a';
            if(!s[u][z])
                s[u][z] = ++n;
            u = s[u][z];
        }
        int v = t2.insert(c2);
        t2id[u].opb(v);
    }

    void addquery(char* c1, char* c2, int i)
    {
        int u = 0;
        for( ; *c1; c1++)
        {
            int z = *c1 - 'a';
            if(!s[u][z])
                break;
            u = s[u][z];
        }
        int v = t2.queryid(c2);
        qs[u].opb(omp(v, i));
    }

    void solve(int x)
    {
        for(auto i: t2id[x])
            t2.rel[i]++;
        for(auto i: qs[x])
            ans[i.o2] = t2.querysum(i.o1);
        for(int o = 0; o < atoz; o++)
            if(s[x][o])
                solve(s[x][o]);
        for(auto i: t2id[x])
            t2.rel[i]--;
    }
};

int n, q;
Trie1<MAX_L + 4 * MAX_N, 27> t1;
char tmp1[MAX_L + 4 * MAX_N], tmp2[MAX_L + 4 * MAX_N], c1[MAX_L + 4 * MAX_N], c2[MAX_L + 4 * MAX_N];

void oM()
{
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s %s", tmp1, tmp2);
        int k = strlen(tmp1);
        int k2 = strlen(tmp2);
        if(k != k2)
            continue;
        int l = -1, r = -1;
        for(int i = 0; i < k; i++)
            if(tmp1[i] != tmp2[i])
                r = i;
        if(r == -1)
            continue;
        for(int i = k - 1; ~i; i--)
            if(tmp1[i] != tmp2[i])
                l = i;
        int tot1 = 0, tot2 = 0;
        for(int i = l; i <= r; i++)
            c1[tot1++] = tmp1[i];
        c1[tot1++] = '{';
        for(int i = l; i <= r; i++)
            c1[tot1++] = tmp2[i];
        c1[tot1++] = '{';
        for(int i = l - 1; ~i; i--)
            c1[tot1++] = tmp1[i];
        for(int i = l; i <= r; i++)
            c2[tot2++] = tmp1[i];
        c2[tot2++] = '{';
        for(int i = l; i <= r; i++)
            c2[tot2++] = tmp2[i];
        c2[tot2++] = '{';
        for(int i = r + 1; i < k; i++)
            c2[tot2++] = tmp1[i];
        c1[tot1] = c2[tot2] = 0;
        t1.insert(c1, c2);
    }
    for(int i = 1; i <= q; i++)
    {
        scanf("%s %s", tmp1, tmp2);
        int k = strlen(tmp1);
        int k2 = strlen(tmp2);
        if(k != k2)
            continue;
        int l = -1, r = -1;
        for(int i = 0; i < k; i++)
            if(tmp1[i] != tmp2[i])
                r = i;
        if(r == -1)
            continue;
        for(int i = k - 1; ~i; i--)
            if(tmp1[i] != tmp2[i])
                l = i;
        int tot1 = 0, tot2 = 0;
        for(int i = l; i <= r; i++)
            c1[tot1++] = tmp1[i];
        c1[tot1++] = '{';
        for(int i = l; i <= r; i++)
            c1[tot1++] = tmp2[i];
        c1[tot1++] = '{';
        for(int i = l - 1; ~i; i--)
            c1[tot1++] = tmp1[i];
        for(int i = l; i <= r; i++)
            c2[tot2++] = tmp1[i];
        c2[tot2++] = '{';
        for(int i = l; i <= r; i++)
            c2[tot2++] = tmp2[i];
        c2[tot2++] = '{';
        for(int i = r + 1; i < k; i++)
            c2[tot2++] = tmp1[i];
        c1[tot1] = c2[tot2] = 0;
        t1.addquery(c1, c2, i);
    }
    t1.solve(0);
    for(int i = 1; i <= q; i++)
        printf("%d\n", t1.ans[i]);
}

void oC()
{
    ;
}

void oE()
{
    ; //printf("%d\n", (int)('{' - 'a'));
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    oE();
    int T = 1;
    while(T--)
        oM(), oC();
    return 0;
}
