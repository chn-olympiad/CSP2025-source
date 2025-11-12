#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5000002;
typedef unsigned long long ull;
const ull JIN = 131;

ull p[MAXN];
bool bbb = true;
struct Node
{
    int len;
    string s;
    vector <ull> sum;
    int idd;

    void Cin()
    {
        s = "";
        cin >> s;
        len = s.length();
        s = ' ' + s;
        sum.clear();
        for(int i = 0;i <= len;i++)
            sum.push_back(0);
        for(int i = 1;i <= len;i++)
            sum[i] = sum[i - 1] * JIN + s[i];
        
        if(!bbb) return;
        int tt = 0;
        for(int i = 1;i <= len;i++)
        {
            if(s[i] == 'a')
                continue;
            if(s[i] != 'b' || tt != 0)
            {
                bbb = false;
                return;
            }
            tt++;
            idd = i;
        }
    }

    ull Query(int l,int r)
    {
        int len = r - l + 1;
        return sum[r] - sum[l - 1] * p[len];
    }
};

int n,q;
Node t1,t2;
Node s[MAXN][2];
map <pair <ull,ull>,ll> mp;

void Baoli1()
{
    ll cnt = 0;
    for(int l = 1;l <= t1.len;l++)
    {
        if(t1.Query(1,l - 1) != t2.Query(1,l - 1))
            break;
        for(int r = t1.len;r >= l;r--)
        {
            if(t1.Query(r + 1,t1.len) != t2.Query(r + 1,t2.len))
                break;
            auto p = make_pair(t1.Query(l,r),t2.Query(l,r));
            if(mp.find(p) != mp.end())
                cnt += mp[p];
        }
    }

    cout << cnt << '\n';
}

void Baoli2()
{
    int pl = 1,pr = t1.len;
    for(pl = 1;pl <= t1.len;pl++)
        if(t1.s[pl] != t2.s[pl])
            break;
    for(pr = t1.len;pr >= 1;pr--)
        if(t1.s[pr] != t2.s[pr])
            break;
    
    ll cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(s[i][0].len < pr - pl + 1 || s[i][0].len > t1.len)
            continue;
        for(int l = 1;l <= s[i][0].len;l++)
        {
            if(l > pl)
                break;
            int r = l + (pr - pl + 1) - 1;
            if(r > s[i][0].len)
                break;
            
            int L = pl - l + 1,R = pr + s[i][0].len - r;
            if(t1.Query(L,R) == s[i][0].Query(1,s[i][0].len) && t2.Query(L,R) == s[i][1].Query(1,s[i][1].len))
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << '\n';
}

void Baoli3()
{
    int id = 0;
    for(int i = 1;i <= t1.len;i++)
    {
        if(t1.s[i] == 'b')
        {
            id = i;
            break;
        }
    }
    
    ll cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(s[i][0].len > t1.len)
            continue;
        if(s[i][0].idd > id)
            continue;
        if(s[i][0].len - s[i][0].idd + 1 > t1.len - id + 1)
            continue;
        int L = id - s[i][0].idd + 1,R = id + (s[i][0].len - s[i][0].idd + 1) - 1;
        if(t1.Query(L,R) == s[i][0].Query(1,s[i][0].len) && t2.Query(L,R) == s[i][1].Query(1,s[i][1].len))
            cnt++;
    }

    cout << cnt << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    p[0] = 1;
    for(int i = 1;i < MAXN;i++)
        p[i] = p[i - 1] * JIN;
    
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        s[i][0].Cin(),s[i][1].Cin();
        mp[make_pair(s[i][0].Query(1,s[i][0].len),s[i][1].Query(1,s[i][1].len))]++;
    }
    
    for(int qq = 1;qq <= q;qq++)
    {
        t1.Cin(),t2.Cin();
        if(t1.len != t2.len)
        {
            cout << 0 << "\n";
            continue;
        }

        if(t1.len <= (bbb ? 300 : 2230))
            Baoli1();
        else if(!bbb)
            Baoli2();
        else
            Baoli3();
    }

    return 0;
}