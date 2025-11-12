#include<bits/stdc++.h>
using namespace std;
#define int long long
int cnt[20];
string s;
bool is_num(char x)
{
    return x>='0'&&x<='9';
}
signed main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(is_num(s[i]))
            cnt[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        if(cnt[i]!=0)
        {
            for(int j=1;j<=cnt[i];j++)
                cout<<i;
        }

    return 0;
}

