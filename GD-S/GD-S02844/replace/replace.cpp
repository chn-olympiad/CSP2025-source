#include <bits/stdc++.h>
using namespace std;
#define int long long
const int _ = 1e6+5;

bool START;

int rd()
{
    int x = 0, f = 1;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') f = -1;
    for(; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return x * f;
}

struct node{map< pair<int, int>, int> mp; int f;}t[_];

string s1, s2;
int n, q, cnt, ans, awa;

void insert()
{
    int p = 0;
    for(int i = 0; i < s1.size(); i++)
    {
        if(!t[p].mp[{s1[i]-'a', s2[i]-'a'}]) p = t[p].mp[{s1[i]-'a', s2[i]-'a'}] = ++cnt;
        else p = t[p].mp[{s1[i]-'a', s2[i]-'a'}];
    }
    t[p].f++;
}

void query(int l)
{
    int p = 0, res = 0;
    for(; l < s1.size(); l++)
    {
        p = t[p].mp[{s1[l]-'a', s2[l]-'a'}];
        if(!p) break;
        res += (s1[l] != s2[l]);
        if(awa == res) ans += t[p].f;
    }
}

signed main()
{
     freopen("replace.in", "r", stdin);
     freopen("replace.out", "w", stdout);
    n = rd(), q = rd();
    while(n--) cin >> s1 >> s2, insert();
    while(q--)
    {
        ans = 0;
        cin >> s1 >> s2;
        for(int i = 0; i < s1.size(); i++) awa += (s1[i] != s2[i]);
        for(int i = 0; i < s1.size(); i++) query(i);
        cout << ans << "\n";
    }
    return 0;
}