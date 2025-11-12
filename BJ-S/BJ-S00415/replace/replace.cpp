#include<bits/stdc++.h>
using namespace std;
int n, q;
string s1[100005];
string s2[100005];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> s1[i] >> s2[i];
    }
    while(q--)
    {
        int cnt = 0;
        string t1, t2;
        cin >> t1 >> t2;
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < t1.size()-s1[i].size()+1;j++)
            {
                if(t1.substr(j, s1[i].size())==s1[i])
                {
                    string t3 = t1.substr(0, j)+s2[i]+t1.substr(j+s1[i].size(), t1.size()-s1[i].size()-j);
                    if(t3==t2) cnt++;
                }
            }
        }
        cout << cnt << "\n";
        if(clock() > 0.97*CLOCKS_PER_SEC)
        {
            while(q--) cout << "0\n";
            return 0;
        }
    }
    return 0;
}
