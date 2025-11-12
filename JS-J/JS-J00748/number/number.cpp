#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5e5 + 5;
string s;
int mp[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    for(auto c : s)
    {
        if(isdigit(c))
        {
            mp[c - '0']++;
        }
    }
    for(int i = 9;i >= 0;i--)
    {
        while(mp[i]--) cout << i;
    }
    cout << endl;
    return 0;
}