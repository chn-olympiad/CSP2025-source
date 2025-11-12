#include<bits/stdc++.h>
using namespace std;
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long sum=0;
    string s;
    cin>>s;
    while(1)
    {
        for(long long ci=0;ci<s.size();ci++)
        {
            if(s[ci]>='0'&&s[ci]<='9')
            {
                sum=sum*10+int(s[ci]-'0');
            }

        }
        break;
    }
    int yy=0;
    long long a[1000001];
    long long ci=1;
    while(1)
    {
        if(sum==0) break;
        a[ci]=sum%10;
        sum=sum/10;
        yy++;
        ci++;
    }
    sort(a+1,a+1+yy,cmp);
    for(long long ci=1;ci<=yy;ci++)
    {
        sum=sum*10+a[ci];
    }
    cout<<sum;
    return 0;
}
