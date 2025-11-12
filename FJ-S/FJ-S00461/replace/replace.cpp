#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n, q, f[5600005][27], c[5600005], nxt[5600005], s[5600005], qq[5600005], ql = 1, qr, cnt;
string s1, s2;

int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s1 >> s2;
        if(s1 == s2) continue;
        int w = s1.length();
        s1 = " " + s1;
        s2 = " " + s2;
        string ss = "";
        int l = 1, r = w;
        while(s1[l] == s2[l]) l++;
        while(s1[r] == s2[r]) r--;
        for(int i = 1; i < l; i++)
            ss += s1[i];
        ss += '{';
        for(int i = l; i <= r; i++)
            ss += s1[i];
        ss += '{';
        for(int i = l; i <= r; i++)
            ss += s2[i];
        ss += '{';
        for(int i = r + 1; i <= w; i++)
            ss += s1[i];
        int x = 0;
        for(char c : ss)
        {
            if(!f[x][c - 'a']) f[x][c - 'a'] = ++cnt;
            x = f[x][c - 'a'];
        }
        c[x]++;
    }
    for(int i = 0; i <= 26; i++)
        if(f[0][i])
        {
            qq[++qr] = f[0][i];
            s[f[0][i]] = c[f[0][i]];
        }
    while(ql <= qr)
    {
        int x = qq[ql];
        ql++;
        s[x] = c[x] + s[nxt[x]];
        for(int i = 0; i <= 26; i++)
            if(f[x][i])
            {
                nxt[f[x][i]] = f[nxt[x]][i];
                qq[++qr] = f[x][i];
            }
            else f[x][i] = f[nxt[x]][i];
    }
    for(int i = 1; i <= q; i++)
    {
        cin >> s1 >> s2;
        if(s1.length() != s2.length())
        {
            cout << "0\n";
            continue;
        }
        int w = s1.length();
        s1 = " " + s1;
        s2 = " " + s2;
        string ss = "";
        int l = 1, r = w;
        while(s1[l] == s2[l]) l++;
        while(s1[r] == s2[r]) r--;
        for(int i = 1; i < l; i++)
            ss += s1[i];
        ss += '{';
        for(int i = l; i <= r; i++)
            ss += s1[i];
        ss += '{';
        for(int i = l; i <= r; i++)
            ss += s2[i];
        ss += '{';
        for(int i = r + 1; i <= w; i++)
            ss += s1[i];
        int x = 0, anss = 0;
        for(char c : ss)
        {
            x = f[x][c - 'a'];
            anss += s[x];
        }
        cout << anss << "\n";
    }
    return 0;
}
