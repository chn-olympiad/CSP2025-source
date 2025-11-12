#include<bits/stdc++.h>
using namespace std;
int n,q;
string str1[200010],str2[200010];
unsigned long long s[2000010];
unsigned long long s1[2000010],t[200010];
unsigned long long bs[2000010];
const unsigned long long base = 131;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> q;
    bs[0] = 1;
    for(int i = 1;i<= 2e6;i ++) bs[i] = bs[i - 1] * base;
    for(int i = 1;i <= n;i ++) cin >> str1[i] >> str2[i];
    for(int i = 1;i <= n;i ++) 
    {
        for(int j = 0;j < str1[i].size();j ++)
        {
            s[i] = s[i] * base + str1[i][j] - 'a' + 1;
            t[i] = t[i] * base + str2[i][j] - 'a' + 1;
        }
    }
    for(int i = 1;i <= q;i ++)
    {
        string t1,t2;
        cin >> t1 >>t2;
        s1[1] = t1[0] - 'a'  + 1;
        unsigned long long tt = 0;
        for(int k = 1;k <= t1.size();k ++)
        {
            s1[k + 1] = s1[k] * base +  t1[k] - 'a' + 1;
        }
        for(int j = 0;j < t2.size();j ++)
        {
            tt= tt * base + t2[j] - 'a' + 1;
        }
        int ans = 0;
        string s2 = t1;
        for(int j  = 1;j <= n;j ++) 
        {
            for(int k = 0;k + str1[j].size() <= t1.size();k ++)
            {
                if(s[j] == s1[k + str1[j].size()] - s1[k] * bs[str1[j].size()])
                {
                    s2 = t1;
                    string str11 = s2.substr(0,k);
                    string str12 = s2.substr(k,str1[j].size());
                    string str13 = s2.substr(k + str1[j].size());   
                    string str14 = str11 + str2[j] + str13;
                    if(str14 == t2) ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}