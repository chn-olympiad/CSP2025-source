#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int n, q;
string s1[N], s2[N];
int main()
{
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    cin >> n >> q;
    for(int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
    while(q -- )
    {
        string a, b;
        cin >> a >> b;
        int cnt = 0;
        for(int i = 1; i <= n; i ++ )
        {
            bool state = false;
            for(int j = 0; j < a.size(); j ++)
            {
                bool flag = true;
                for(int k = 0; k < s1[i].size(); k ++)
                    if(a[j + k] != s1[i][k])
                        flag = false;
                if(flag == true) 
                {
                    string p1 = a.substr(0, j);
                    string p2 = a.substr(j + s1[i].size(), n - j - s1[i].size() + 1);
                    if(p1 + s2[i] + p2 == b) state = true; 
                }
            }
            if(state == true) cnt ++;
        }
        cout << cnt << endl;
    }
    return 0;
}