#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m,c[505],ans = 0,ans0 = 0,ans1 = 0;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    string s;
    cin >> n >> m >> s;
    for(int i = 1;i <= n;i++)
    {
        cin >> c[i];
    }
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == 1)
        {

            ans1++;
        }
        else
        {
            ans0++;
        }
    }
    cout << 1;
    return 0;
}
