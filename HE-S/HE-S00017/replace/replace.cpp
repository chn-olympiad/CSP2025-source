#include<bits/stdc++.h>
#include<string>
using namespace std;
bool flag = false;
int n,q,ans = 0;
string t[3];
string s[200005][3];
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    for(int i = 1;i <= q;i++)
    {
        ans = 0;
        cin >> t[1] >> t[2];
        for(int j = 1;j <= n;j++)
        {
            string temp = t[1];
            flag = false;
            for(int k = 0;k < temp.length();k++)
            {
                if(temp[k] == s[j][1][0] && !flag)
                {
                    for(int pos = 0;pos < s[j][1].length();pos++)
                    {
                        temp[k + pos] = s[j][2][pos];
                    }
                    flag = true;
                }
            }
            if(temp == t[2]) ans++;
        }
        cout << ans << endl;
    }
    fclose(stdin);
    fclose(stdout);
}
