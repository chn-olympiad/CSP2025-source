#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int n;
    cin >>n;
    int maxn = 0;
    for(int i = 1;i <= n;i++)
    {
        if(s[i] >= '1' && s[i] <= 9)
        {
            maxn = s[i];
        }
    }
    cout << maxn;



    return 0;
}
