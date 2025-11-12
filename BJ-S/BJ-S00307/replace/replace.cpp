#include<bits/stdc++.h>
#define int long long
#define ULL unsigned long long
using namespace std;
const int N = 2e5 + 5;
int n;
int q;
int ans;
vector<char> v1[N];
vector<char> v2[N];
vector<char> vt1[N];
vector<char> vt2[N];
int findB(string s)
{
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == 'b') return i;
    }
}
string substr_(string s,int l,int r)
{
    string s2;
    s2 = "";
    for(int i = l;i <= r;i++)
    {
        s2 += s[i];
    }
    return s2;
}
void calc_B()
{

    for(int i = 1;i <= q;i++)
    {
        string t1;
        string t2;
        t1 = "";
        t2 = "";
        for(auto k : vt1[i]) t1 += k;
        for(auto k : vt2[i]) t2 += k;
        int id1 = findB(t1);
        int id2 = findB(t2);
        for(int j = 1;j <= n;j++)
        {
            string s1 = "";
            string s2 = "";
            s1 = "";
            s2 = "";

            for(auto k : v1[i]) s1 += k;
            for(auto k : v2[i]) s2 += k;
            int id3;
            id3 = findB(s1);
            int id4;
            id4 = findB(s2);
            cout << id1 << " " << id2 << '\n';
            if(id1 < id3 || id1 - id2 != id3 - id4) continue;
            if(substr_(t1,0,(id1 - id3 - 1)) == substr_(t2,0,(id1 - id3 - 1)) && s2 == substr_(t2,id1 - id3,id1 - id3 + s2.length() - 1) && substr_(t1,id1 - id3,id1 - id3 + s1.length() - 1) == s1 && substr_(t1,id1 - id3 + s1.length(),t1.length() - 1) == substr_(t2,id1 - id3 + s1.length(),t2.length() - 1)) ans++,cout << j << '\n';
        }
    }
    cout << ans << '\n';
    return;
}
signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    bool flag = false;
    for(int i = 1;i <= n;i++)
    {
        string s1,s2;
        cin >> s1;
        cin >> s2;
        int cntb = 0;
        for(int j = 0;j < s1.length();j++)
        {
            if(s1[j] == 'b') cntb++;
            if((s1[j] != 'a' && s1[j] != 'b') || cntb >= 2) flag = true;
            v1[i].push_back(s1[j]);
        }
        cntb = 0;
        for(int j = 0;j < s2.length();j++)
        {
            if(s2[j] == 'b') cntb++;
            if((s2[j] != 'a' && s2[j] != 'b') || cntb >= 2) flag = true;
            v2[i].push_back(s2[j]);
        }
    }
    for(int i = 1;i <= q;i++)
    {
        string t1,t2;
        cin >> t1;
        cin >> t2;
        int cntb = 0;
        for(int j = 0;j < t1.length();j++)
        {
            if(t1[j] == 'b') cntb++;
            if((t1[j] != 'a' && t1[j] != 'b') || cntb >= 2) flag = true;
            vt1[i].push_back(t1[j]);
        }
        cntb = 0;
        for(int j = 0;j < t2.length();j++)
        {
            if(t2[j] == 'b') cntb++;
            if((t2[j] != 'a' && t2[j] != 'b') || cntb >= 2) flag = true;
            vt2[i].push_back(t2[j]);
        }
    }
    if(!flag) calc_B();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
