#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL len,tw[15];
string s;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    len = s.size();
    for(int i=0;i<len;i++)
        if(s[i] >= '0' && s[i] <= '9')
            tw[ s[i] - 48 ]++;
    for(int i=9;i>=0;i--)
        while(tw[i]--) cout << i;
    return 0;
}
