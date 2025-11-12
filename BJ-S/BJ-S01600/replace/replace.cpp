#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 5e6 + 5;
struct node
{
    int id;
    char c;
};
string s[N][3], t1, t2, x[N], z[N], x1, z1;
int l[N], r[N], tail = 27, son[M][27];
vector <int> Trie[M], cnt;
void Build(int x)
{
    int now = l[x], idx = s[x][1][now] - 'a' + 1;
    Trie[idx].push_back(x);
    while(now != r[x])
    {
        int flag = idx;
        now++;
        if(son[idx][s[x][1][now] - 'a' + 1] != 0)
        {
            idx = son[idx][s[x][1][now] - 'a' + 1];
            Trie[idx].push_back(x);
        }
        else
        {
            son[idx][s[x][1][now] - 'a' + 1] = tail;
            Trie[tail].push_back(x);
            idx = tail++;
        }
    }
}
void Find(int l1, int r1)
{
    cnt.clear();
    int now = l1, idx = t1[now] - 'a' + 1;
    if(Trie[idx].empty())
        return;
    while(now != r1)
    {
        int flag = idx;
        now++;
        if(son[idx][t1[now] - 'a' + 1] != 0)
            idx = son[idx][t1[now] - 'a' + 1];
        else
            return;
    }
    cnt = Trie[idx];
}
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i][1] >> s[i][2];
        r[i] = l[i] = -1;
        for(int j = 0;j < s[i][1].size();j++)
        {
            if(s[i][1][j] != s[i][2][j])
            {
                r[i] = j;
                if(l[i] == -1)
                    l[i] = j;
            }
            if(l[i] == -1)
                x[i] = x[i] + s[i][1][j];
        }
        for(int j = r[i] + 1;j < s[i][1].size();j++)
            z[i] = z[i] + s[i][1][j];
        Build(i);
    }
    for(int i = 1;i <= q;i++)
    {
        cin >> t1 >> t2;
        if(t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        int l1 = -1, r1 = -1;
        x1 = z1 = "";
        for(int j = 0;j < t1.size();j++)
        {
            if(t1[j] != t2[j])
            {
                r1 = j;
                if(l1 == -1)
                    l1 = j;
            }
            if(l1 == -1)
                x1 = x1 + t1[j];
        }
        for(int j = r1 + 1;j < t1.size();j++)
            z1 = z1 + t1[j];
        Find(l1, r1);
        if(cnt.empty())
        {
            cout << 0 << endl;
            continue;
        }
        int cnt1 = 0;
        for(int j = 0;j < cnt.size();j++)
        {
            int f = cnt[j];
            if(r[f] - l[f] != r1 - l1)
                continue;
            bool flag = true;
            if(x[f] != "")
            {
                if(x1.size() < x[f].size())
                {
                    flag = false;
                    continue;
                }
                int f1 = x1.size() - 1;
                for(int k = x[f].size() - 1;k >= 0;k--)
                {
                    if(x[f][k] != x1[f1--])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if(z[f] != "")
            {
                if(z1.size() < z[f].size())
                {
                    flag = false;
                    continue;
                }
                int f1 = 0;
                for(int k = 0;k < z[f].size();k++)
                {
                    if(z[f][k] != z1[f1++])
                    {
                        flag = false;
                        break;
                    }
                }
            }
            for(int k = 0;k <= r1 - l1;k++)
            {
                if(s[f][2][k + l[f]] != t2[k + l1])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                cnt1++;
        }
        cout << cnt1 << endl;
    }
    return 0;
}