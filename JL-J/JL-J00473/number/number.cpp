#include <bits/stdc++.h>
using namespace std;
map <int,int> mp;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]>='0'&&s[i]<='9')
            mp[s[i]-'0']++;
    for(int i=9;i>=0;i--)
        for(int j=1;j<=mp[i];j++)
            printf("%d",i);
    puts("");
    return 0;
}
