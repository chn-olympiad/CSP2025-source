#include<bits/stdc++.h>
using namespace std;
string s;
int a[15];
long long l,c,sum;
int main(void)
{
    //number
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    l=s.size();
    for(int i=0;i<l;i++)
    {
        if(s[i]=='0' || s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9' )
        {
            int t;
            t=s[i]-'0';
            a[t]++;
        }
    }
    for(int i=9;i>=1;i--)
    {
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
        sum=sum+a[i];
    }
    if(sum==0)
    {
        cout<<0;
    }
    else
    {
        for(int i=1;i<=a[0];i++)
        {
            cout<<0;
        }
    }
    return 0;
}
