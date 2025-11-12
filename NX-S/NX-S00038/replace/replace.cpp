#include<bits/stdc++.h>
using namespace std;
string s[200005][5], t1, t2;
int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i ++)
    {
        cin >> s[i][1] >> s[i][2];
    }
    for(int w = 0; w < q; w ++)
    {
        cin >> t1 >> t2;
        string stra, strb;
        for(int i = 0; i < t1.size(); i ++)
        {
            if(t1[i] != t2[i])
            {
                stra += t1[i];
                strb += t2[i];
                i++;
                while(t1[i] == t2[i])
                {
                    stra += t1[i];
                    strb += t2[i];
                    i++;
                }
                stra += t1[i];
                strb += t2[i];
                break;
            }
        }
        //cout << stra << " " << strb << endl;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < s[i][1].size(); j++)
            {
                if(s[i][1][j] == stra[0] && s[i][2][j] == strb[0])
                {
                    bool T = 1;
                    for(int k = j; k <= stra.size(); k ++)
                    {
                        if(s[i][1][k] != stra[k-j] || s[i][2][k] != strb[k-j])T = 0;
                    }
                    if(T == 1)
                    {
                        cnt++;
                        break;
                    }
                }

            }
        }
        cout << cnt << endl;
    }
    return 0;
}
