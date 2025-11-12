#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt[10];
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.length();i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<cnt[i];j++)
        {
            cout<<i;
        }
    }
    cout<<endl;
    return 0;
}
