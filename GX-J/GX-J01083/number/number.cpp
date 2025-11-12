#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long a[1000005],n=0;
    cin>>s;
    for(long long i=0;i<s.size();i++)
    {
        if(s[i]>='0' and s[i]<='9')
        {
            n++;
            a[n]=s[i]-'0';
        }
    }
    for(long long i=1;i<=n-1;i++)
    {
        for(long long j=1;j<=n-i;j++)
        {
            if(a[j]<a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
    for(long long i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
