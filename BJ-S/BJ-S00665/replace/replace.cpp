#include "bits/stdc++.h"
using namespace std;
const int N = 2e5+100;
string s1[N],s2[N];
int n,q;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    for(int i = 1;i <= n;i++)
        cin >> s1[i] >> s2[i];
    while(q--)
    {
        int ans = 0;
        string t1,t2;
        cin >> t1 >> t2;
        for(int i = 1;i <= n;i++)
        {
            int sum1 = 0,sum2 = 0,sum11 = 0,sum22 = 0;
            for(int j = 0;j < s1[i].size();j++)
            {
                if(j != s1[i].size()-1)
                {
                    if(s1[i][j] != s1[i][j+1])
                    {
                        sum1 = j+1;
                        break;
                    }
                }
                else
                    sum1 = s1[i].size();

            }
            for(int j = 0;j < s2[i].size();j++)
            {
                if(j != s2[i].size()-1)
                {
                    if(s2[i][j] != s2[i][j+1])
                    {
                        sum2 = j+1;
                        break;
                    }
                }
                else
                    sum2 = s2[i].size();
            }
            for(int j = 0;j < t1.size();j++)
            {
                if(j != t1.size()-1)
                {
                    if(t1[j] != t1[j+1])
                    {
                        sum11 = j+1;
                        break;
                    }
                }
                else
                    sum11 = t1.size();
            }
            for(int j = 0;j < t2.size();j++)
            {
                if(j != t2.size()-1)
                {
                    if(t2[j] != t2[j+1])
                    {
                        sum22 = j+1;
                        break;
                    }
                }
                else
                    sum22 = t2.size();
            }
            //cout << sum1 << ' ' << sum2 << ' ' << sum11 << ' ' << sum22 << "\n";
            if(sum11-sum1+sum2 == sum22)
                ans++;
        }
        cout << ans << "\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
