#include <bits/stdc++.h>
#define PII std::pair<int,int>
#define all(v) v.begin(),v.end()
#define fro(i,a,b) for (int i = a; i <= b; i++)
#define i64 unsigned long long
using namespace std;
bool bg;
inline void chkmin (int& x , int y) { (x > y) && (x = y); }
inline void chkmax (int& x , int y) { (x < y) && (x = y); }
const int N = 2e5 + 5 , S = 5e6 + 5;
const i64 Base = 173;

int n , q;
int now = 1 , idx;
i64 _[S << 2];
i64 power[S];
struct Hash 
{
    i64* h;
    inline void init (std :: string& s)
    {
        h = _ + now ; now += s.size () + 1;
        for (int i = 1; i <= s.size (); i++)
            h[i] = h[i - 1] * Base + s[i - 1];
    }
    inline i64 gethash (int l , int r)
    {
        return h[r] - h[l - 1] * power[r - l + 1];
    }
} a[N << 1] , b[N << 1];
struct Info { i64 h1 , h2; int l , r , id; };
std :: map < std :: pair <i64 , i64> , int > mp ;
std :: map < std :: pair <i64 , i64> , PII > me ;
std :: vector <Info> e[N];

bool ed;
signed main ()
{
    freopen ("replace.in" , "r" , stdin);
    freopen ("replace.out" , "w" , stdout);
    ios::sync_with_stdio (0); std::cin.tie (0); std::cout.tie (0);
    power[0] = 1;
    fro (i , 1 , 5000000) power[i] = power[i - 1] * Base;
    std :: cin >> n >> q;
    fro (i , 1 , n)
    {
        std :: string s1 , s2;
        std :: cin >> s1 >> s2;
        a[i].init (s1) , a[i + n].init (s2);
        int l = 0 , r = 0 , len = s1.size ();
        i64 a1 = a[i].gethash (1 , len) , a2 = a[i + n].gethash (1 , len);
        if (me.count ({a1 , a2}))
        {
            PII tmp = me[{a1 , a2}];
            e[tmp.first][tmp.second].id++;
            continue;
        }
        while (l < len && s1[l] == s2[l]) l++;
        while (r < len && s1[len - r - 1] == s2[len - r - 1]) r++;
        if (l + r > len) continue;
        i64 w1 = a[i].gethash (l + 1 , len - r) , w2 = a[i + n].gethash (l + 1 , len - r);
        if (!mp.count ({w1 , w2})) mp[{w1 , w2}] = ++idx;
        int id = mp[{w1 , w2}];
        e[id].push_back ({a1 , a2 , l , r , 1});
        me[{a1 , a2}] = {id , e[id].size () - 1};
    }
    fro (now , 1 , q)
    {
        std :: string t1 , t2;
        std :: cin >> t1 >> t2;
        b[now].init (t1) , b[now + q].init (t2);
        int l = 0 , r = 0 , len = t1.size ();
        while (l < len && t1[l] == t2[l]) l++;
        while (r < len && t1[len - r - 1] == t2[len - r - 1]) r++;
        i64 w1 = b[now].gethash (l + 1 , len - r) , w2 = b[now + q].gethash (l + 1 , len - r);
        int op = mp[{w1 , w2}] , res = 0;
        for (auto j : e[op])
        {
            int x = j.l , y = j.r;
            if (x > l && y > r) continue;
            i64 w1 = b[now].gethash (l + 1 - x , len - r + y);
            i64 w2 = b[now + q].gethash (l + 1 - x , len - r + y);
            if (w1 == j.h1 && w2 == j.h2) res += j.id;
        }
        std :: cout << res << "\n";
    }
    cerr << "\n" << fabs (&bg - &ed) / 1024. / 1024. << " Mib\n";
    return 0;
}