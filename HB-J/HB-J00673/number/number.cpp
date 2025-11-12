#include<bits/stdc++.h>
using namespace std;
string b;
long long a[1000005],n;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>b;
    for(long long i=0;i<b.size();i++)
    {
        if('0'<=b[i]&&b[i]<='9')
        {
            a[++n]=(b[i]-'0');
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++)
    {
        cout<<a[i];
    }
    return 0;
}
