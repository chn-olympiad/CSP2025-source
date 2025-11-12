#include<bits/stdc++.h>
using namespace std;
int n, q, ans;
struct tr
{
    int ch[5000005][26];
    int tag[5000005];
    int fail[5000005];
    string to[5000005];
    bool vis[5000005];
    int cnt, sum;
    tr()
    {
        memset(fail, -1, sizeof(fail));
        // fail[0] = 0;
    }
    void insert(string x, string y)
    {
        int p = 0;
        for(int i = 0; i < x.size(); i ++)
        {
            if(ch[p][x[i] - 'a'] == 0)
            {
                ch[p][x[i] - 'a'] = ++ cnt;
            }
            // printf("%d -> %d (%c)\n", p, ch[p][x[i] - 'a'], x[i]);
            p = ch[p][x[i] - 'a'];
        }
        // printf("tag[%d] = %d\n", p, sum + 1);
        tag[p] = ++ sum;
        to[sum] = y;
    }
    void build(int p, int fa)
    {
        // int p = 0;
  
        // printf("%d -> %d\n", fa, p);
        for(int i = 0; i < 26; i ++)
        {
            if(ch[p][i])
            {
                if(p == 0)
                {
                    fail[ch[p][i]] = 0;
                }
                else
                {
                    fail[ch[p][i]] = ch[fail[p]][i];
                    // printf("fail[%d] -> ch[fail[%d]][%d]", ch[p][i], p, i);
                }
                
                
                build(ch[p][i], p);
            }
            else
            {
                ch[p][i] = ch[fail[p]][i];
            }
        }
    }
    void find(string a, string b)
    {
        int p = 0;
        for(int i = 0; i < a.size(); i ++)
        {
            p = ch[p][a[i] - 'a'];
            for(int j = p; ~j && !vis[j]; j = fail[j])
            {
                // printf("%d : %d\n", i, j);
                
                if(tag[j] != 0)
                {
                    // vis[j] = 1;
                    string x = a;
                    int n = 0;
                    for(int k = i - to[tag[j]].size() + 1; k <= i; k ++)
                    {
                        x[k] = to[tag[j]][n ++];
                    }
                    // cout << x << "\n";
                    if(x == b)
                    {
                        ans ++;
                    }
                }
            }
        }
    }
    void clear()
    {
        // memset(vis, 0, sizeof(vis));
    }
}t;

int main()
{
    freopen("replace.in", "r", stdin);
    // freopen("../sub/replace/replace3.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i ++)
    {
        string a, b;
        cin >> a >> b;
        t.insert(a, b);
    }
    t.build(0, 0);
    // cout << t.ch[7][2] << "fa\n";
    while(q --)
    {
        string a, b;
        cin >> a >> b;
        ans = 0;
        t.clear();
        t.find(a, b);
        printf("%d\n", ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}