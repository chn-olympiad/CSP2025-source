#include<bits/stdc++.h>
using namespace std;
#define int long long
string str;
int buk[10];
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>str;
    for(int i=0;i<(int)str.size();i++)
    {
        if(isdigit(str[i]))
        {
            buk[str[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int k=1;k<=buk[i];k++)
        {
            cout<<i;
        }
    }
    return 0;
}
