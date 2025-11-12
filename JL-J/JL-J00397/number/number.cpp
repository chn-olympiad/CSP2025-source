#include<bits/stdc++.h>

using namespace std;

const int MAXN=1e6+7;
long long t[MAXN]={0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;

    for(int i=0;i<s.size();i++)
    {
        if(s[i]>=48&&s[i]<=57)
        {
            t[s[i]-48]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        for(int j=0;j<t[i];j++)
        {
            cout<<i;
        }
    }

    return 0;
}
