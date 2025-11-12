#include<iostream>
#include<map>
using namespace std;
#define int long long
const int N = 2e5 + 5;

int n,q,pos1[N],pos2[N],pos3[N],pos4[N],diff1[N],diff2[N];
map<int,int> mp;
string s1[N],s2[N],t1[N],t2[N];



signed main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    if(n * n * q > 1000000000)
    {
        bool fff = 1;
        for(int i=1;i<=n;i++)
        {
            cin >> s1[i] >> s2[i]; int cnt = 0;
            for(int j=0;j<s1[i].size();j++) if(s1[i][j] == 'b') cnt++, pos1[i] = j;
            if(cnt > 1) fff = false; cnt = 0;
            for(int j=0;j<s2[i].size();j++) if(s2[i][j] == 'b') cnt++, pos2[i] = j;
            if(cnt > 1) fff = false;
        }
        for(int i=1;i<=q;i++)
        {
            cin >> t1[i] >> t2[i]; int cnt = 0;
            for(int j=0;j<t1[i].size();j++) if(t1[i][j] == 'b') cnt++, pos3[i] = j;
            if(cnt > 1) fff = false; cnt = 0;
            for(int j=0;j<t2[i].size();j++) if(t2[i][j] == 'b') cnt++, pos4[i] = j;
            if(cnt > 1) fff = false;
        }
        if(!fff)
        {
            while(q--) cout << 0 << '\n';
            return 0;
        }
        else
        {
            for(int i=1;i<=n;i++) diff1[i] = pos1[i] - pos2[i], mp[diff1[i]]++;
            for(int i=1;i<=q;i++) diff2[i] = pos3[i] - pos4[i], cout << mp[diff2[i]] << '\n';
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while(q--)
    {
        int ans = 0;
        string t1, t2; cin >> t1 >> t2; t1 = " " + t1; t2 = " " + t2;
        int len = t1.size(), l = -1, r = -1;
        for(int i=1;i<=len;i++)
        if(t1[i] != t2[i]) r = i;
        for(int i=len;i>=1;i--)
        if(t1[i] != t2[i]) l = i;
        string diff1 = "", diff2 = "";
        for(int i=l;i<=r;i++) diff1 = diff1 + t1[i], diff2 = diff2 + t2[i];
        // cout << diff1 << "???" << diff2 << '\n';
        for(int j=1;j<=n;j++)
            for(int i=0;i+r-l<s1[j].size();i++)
            {
                // cout << i << '\n';
                string a1 = s1[j].substr(0,i);
                string a2 = s1[j].substr(i,r-l+1);
                string a3 = s1[j].substr(i+r-l+1,s1[j].size()-(i+r-l+1));
                // cout << i+r-l+1 << " " << s1[j].size()-(i+r-l+1) << " " << i+r-l+1 + s1[j].size()-(i+r-l+1) - 1 << '\n';
                string b1 = s2[j].substr(0,i);
                string b2 = s2[j].substr(i,r-l+1);
                string b3 = s2[j].substr(i+r-l+1,s2[j].size()-(i+r-l+1));
                // cout << a1 << " " << a2 << " " << a3 << " " << s1[j] << '\n';
                // cout << b1 << " " << b2 << " " << b3 << " " << s2[j] << '\n';
                if(a1 == b1 && a3 == b3 && a2 == diff1 && b2 == diff2) ans++;
            }
        cout << ans << "\n";
    }
    return 0;
}
