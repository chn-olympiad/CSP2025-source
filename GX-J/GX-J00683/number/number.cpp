#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a;
    cin>>s;
    for(int i='9';i>=0;i--)
    {
        for(long long j=0;j<s.size();j++)
        {

            if(s[j]==i)
                a+=s[j];
        }
    }
    cout<<a;
    return 0;
}
