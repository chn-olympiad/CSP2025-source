#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //s.substr(1,3);
    string s;
    cin>>s;
    long long n=s.size(),cnt=0;
    for(long long i=0;i<n;i++)
    {
        if('0'<=s[i]&&s[i]<='9')
        {
            a[s[i]-'0']++;
            cnt++;
        }
    }
    for(long long i=9;i>=0;i--)
    {
        for(long long j=1;j<=a[i];j++)cout<<i;
    }
    return 0;
}
