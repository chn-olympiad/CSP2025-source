#include<bits/stdc++.h>
using namespace std;
long long num[9]={0,0,0,0,0,0,0,0,0};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(long long i=0;i<=s.size()-1;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            int x=s[i]-48;
            if(x==9)
            {
                cout<<x;
            }
            else
            {
                num[x]++;
            }
        }
    }
    for(int i=8;i>=0;i--)
    {
        for(long long j=1;j<=num[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
