#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

const int N = 2e5,M = 5e6;
const int b1 = 29,b2 = 31,p1 = 1e9 + 7,p2 = 998244353;
string s[N + 5][5];
int h1[M + 5][5],h2[M + 5][5];
int p[M + 5];
vector<int> ha1[N + 5][5],ha2[N + 5][5];
int pw1[M + 5],pw2[M + 5];
int n,q;

signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s[i][1] >> s[i][2];
    for(int i = 1;i <= n;i++)
    {
        int l = s[i][1].size();
        ha1[i][1].push_back(s[i][1][0] - 'a');
        ha1[i][2].push_back(s[i][2][0] - 'a');
        ha2[i][1].push_back(s[i][1][0] - 'a');
        ha2[i][2].push_back(s[i][2][0] - 'a');
        //cout << i << endl;
        for(int j = 1;j < l;j++)
        {
            ha1[i][1].push_back((ha1[i][1][ha1[i][1].size() - 1] * b1 % p1 + s[i][1][j] - 'a') % p1);
            ha1[i][2].push_back((ha1[i][2][ha1[i][2].size() - 1] * b1 % p1 + s[i][2][j] - 'a') % p1);
            ha2[i][1].push_back((ha2[i][1][ha2[i][1].size() - 1] * b2 % p2 + s[i][1][j] - 'a') % p2);
            ha2[i][2].push_back((ha2[i][1][ha2[i][2].size() - 1] * b2 % p2 + s[i][2][j] - 'a') % p2);
        }
    }
    pw1[0] = pw2[0] = 1;
    for(int i = 1;i <= M;i++)
    {
        pw1[i] = pw1[i - 1] * b1 % p1;
        pw1[i] %= p1;
        pw2[i] = pw2[i - 1] * b2 % p2;
        pw2[i] %= p2;
    }
    while(q--)
    {
        string t1,t2;
        cin >> t1 >> t2;
        h1[0][1] = h2[0][1] = t1[0] - 'a';
        h1[0][2] = h2[0][2] = t2[0] - 'a' ;
        for(int i = 1;i < t1.size();i++)
        {
            h1[i][1] = h1[i - 1][1] * b1 % p1 + t1[i] - 'a';
            h2[i][1] = h2[i - 1][1] * b2 % p2 + t1[i] - 'a';
            h1[i][1] %= p1;
            h2[i][1] %= p2;
        }
        for(int i = 1;i < t2.size();i++)
        {
            h1[i][2] = h1[i - 1][2] * b1 % p1 + t2[i] - 'a';
            h2[i][2] = h2[i - 1][2] * b2 % p2 + t2[i] - 'a';
            h1[i][2] %= p1;
            h2[i][2] %= p2;
        }
        string t = t1 + '#' + t2;
        int l = t.size();
        int res = 0,ans = 0;
        for(int i = 1;i < l;i++)
        {
            int k = p[i - 1];
            while(k > 0 && t[k] != t[i])
            {
                //cout << k << ' ';
                k = p[k - 1];
            }
            if(t[k] == t[i]) p[i] = k + 1;
            //cout << k << ' ' << t[k] << ' ' << t[i] << ' ' << p[i] << ' ';
            if(p[i] == i - t1.size())
            {
                res = max(res,p[i]);
            }
        }
        //cout << endl;
        string tempp = t;
        for(int i = 0;i < l;i++)
        {
            t[i] = tempp[l - i - 1];
        }
        for(int i = 1;i < l;i++)
        {
            int k = p[i - 1];
            while(k > 0 && t[k] != t[i])
            {
                k = p[k - 1];
            }
            if(t[k] == t[i]) p[i] = k + 1;
            if(p[i] == i - t1.size())
            {
                ans = max(ans,p[i]);
            }
        }
        //cout << res << ' ' << ans << endl;
        int templ = res,tempr = t1.size() - ans - 1;
        int k1 = h1[tempr][1] - h1[templ][1] * pw1[tempr - templ] % p1;
        int k2 = h2[tempr][1] - h2[templ][1] * pw2[tempr - templ] % p2;
        k1 = (k1 % p1 + p1) % p1;
        k2 = (k2 % p2 + p2) % p2;
        int out = 0;
        for(int i = 1;i <= n;i++)
        {
            int l1 = s[i][1].size(),l2 = s[i][2].size();
            if(tempr - templ + 1 > l1) continue;
            vector<int> pos;
            for(int j = l1 - 1 - tempr + templ - 1;j < l1;j++)
            {
                int temp1 = ha1[i][1][j] - ha1[i][1][j - tempr + templ] * pw1[tempr - templ] % p1;
                int temp2 = ha2[i][1][j] - ha2[i][1][j - tempr + templ] * pw2[tempr - templ] % p2;
                temp1 = (temp1 % p1 + p1) % p1;
                temp2 = (temp2 % p2 + p2) % p2;
                if(temp1 == k1 && temp2 == k2) pos.push_back(j);
            }
            for(int j = 0;j < pos.size();j++)
            {
                int ll = pos[j] - tempr + templ,rr = pos[j];
                if(ll < templ || l1 - tempr > ans + 1) continue;
                int pos1 = templ - ll,pos2 = tempr + l1 - rr - 1;
                if(pos2 >= t2.size()) continue;
                int tmp1 = h1[pos2][2] - h1[pos1][2] * pw1[pos2 - pos1] % p1;
                int tmp2 = h2[pos2][2] - h2[pos1][2] * pw2[pos2 - pos1] % p2;
                if(tmp1 == ha1[i][2][l2 - 1] && tmp2 == ha2[i][2][l2 - 1])
                {
                    out++;
                }
            }
        }
        cout << out << endl;
    }
    return 0;
}
