#include<bits/stdc++.h>
using namespace std;
int cnt[15];
string s;
int main()//100
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    s="_"+s;
    for(int i=1;i<=s.size()-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        while(cnt[i])
        {
            printf("%d",i);
            cnt[i]--;
        }
    }
}
