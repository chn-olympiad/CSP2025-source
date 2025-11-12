#include <iostream>
using namespace std;

typedef unsigned long long ll;
const ll p = 131;
int n, q;
string s[200001][3];
int slen[200001];
int work(string t1, string t2, int len)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + slen[i] - 1 < len; j++)
        {
            int l = j + slen[i], r = len-1;
            if (t1.substr(j, slen[i]) == s[i][1] && t2.substr(j, slen[i]) == s[i][2] && 
                t1.substr(0, j) == t2.substr(0, j) && 
                t1.substr(l, r-l+1) == t2.substr(l, r-l+1))
                ans++;
        }
    }
    return ans;
}

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i][1] >> s[i][2];
        slen[i] = s[i][1].size();
    }
    for (int i = 1; i <= q; i++)
    {
        string t1, t2;
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        cout << work(t1, t2, t1.size()) << endl;
    }
    return 0;
}
/*
#include <iostream>
using namespace std;

string t1, t2;
typedef unsigned long long ll;
const ll p = 10;
int n, q;
ll s[200001][3];
int slen[200001];
ll base[1000001];
ll h1[200001], h2[200001];
void init()
{
    base[0] = 1;
    for (int i = 1; i <= 1e6; i++)
        base[i] = base[i-1] * p;
}
ll Hash(string s, ll *h)
{
    for (int i = 0; i < s.size(); i++)
    {
        h[i+1] = h[i] * p + s[i] - 'a';
    }
    return h[s.size()];
}
ll debugHash(string s)
{
    ll t = 0;
    for (int i = 0; i < s.size(); i++)
    {
        t = t * p + s[i] - 'a';
    }
    return t;
}
ll subhash(int l, int len, ll *h)
{
    l++;
    int r = l+len-1;
    return h[r] - h[l-1] * base[l-1];
}
int work(ll len)
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j + slen[i] - 1 < len; j++)
        {
            int l = j + slen[i], r = len;
            ll a = debugHash(t1.substr(j, slen[i])), b = debugHash(t1.substr(j, slen[i]));

            if (subhash(j, slen[i], h1) == s[i][1] && subhash(j, slen[i], h2) == s[i][2] && subhash(0, j, h1) == subhash(0, j, h2) && subhash(l, r-l+1, h1) == subhash(l, r-l+1, h2))
                ans++;
        }
    }
    return ans;
}

int main()
{
    init();
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        s[i][1] = Hash(s1, h1), s[i][2] = Hash(s2, h2);
        slen[i] = s1.size();
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t1 >> t2;
        if (t1.size() != t2.size())
        {
            cout << 0 << endl;
            continue;
        }
        Hash(t1, h1);
        Hash(t2, h2);
        cout << work(t1.size()) << endl;
    }
    return 0;
}*/