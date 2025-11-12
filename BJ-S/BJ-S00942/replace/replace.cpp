#include<bits/stdc++.h>
using namespace std;
string s1[105],s2[105],s,t;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 1;i <= n;i++) cin >> s1[i] >> s2[i];
    while(q--)
    {
        int cnt = 0;
        cin >> s >> t;
        int len = s.length();
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j < len;j++)
            {
                if(j+s1[i].length() >= len) break;
                string k1 = s.substr(j,s1[i].length());
                if(k1 != s1[i]) continue;
                string k = s.substr(0,j)+s2[i]+s.substr(j+s1[i].length(),len-j-s1[i].length());
                //cout << k << " ";
                if(k == t) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
