#include<bits/stdc++.h>
#include<string>
#include<cstring>
using namespace std;
string s;
long long b[15];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if((s[i]-'0')>=0&&(s[i]-'0')<=9)
        {
            b[s[i]-'0']+=1;
        }
    }
    for(int i=9;i>=0;i--)
        for(long long j=1;j<=b[i];j++)
            cout<<i;
    return 0;
}
