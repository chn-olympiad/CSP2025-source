#include<bits/stdc++.h>
using namespace std;
string s[200010][5];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    while(q--)
    {
        int cnt = 0;
        string t1,t2;
        cin >> t1 >> t2;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 0; j <= t1.size() - s[i][1].size() + 1; j++)
            {
                bool flag = 1;
                for(int k = j; k < j + s[i][1].size(); k++)
                {
                    if(!(t1[k] == s[i][1][k] && t2[k] == s[i][2][k])) flag = 0;
                }
                for(int k = 0; k < j; k++)
                {
                    if(t1[k] != t2[k]) flag = 0;
                }
                for(int k = j + s[i][1].size(); k < t1.size(); k++)
                {
                    if(t1[k] != t2[k]) flag = 0;
                }
                if(flag == 1) cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
