#include <bits/stdc++.h>
using namespace std;
int NOans;
int YESans;
int ans[1000005];
int main()
{
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    int n, m;
    string s;
    int c[1000001];
    cin >> n >> m;
    cin >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(NOans > c[i])
        {
            NOans++;
        }
        if(s[i] == '1')
        {
            YESans++;
            ans[i] = s[i]-32;
        }
        else if(s[i] == '0')
        {
            NOans++;
        }
    }
    cout << YESans+1;
    return 0;
}
