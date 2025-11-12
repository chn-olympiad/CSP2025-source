#include<bits/stdc++.h>
using namespace std;
string s,ans={};
int b[20];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    getline(cin,s);
    int lon=s.size();
    for(int i=0;i<lon;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            b[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=1;j<=b[i];j++)
        {
            ans+=i+'0';
        }

    }
    cout<<ans;
    return 0;
}
