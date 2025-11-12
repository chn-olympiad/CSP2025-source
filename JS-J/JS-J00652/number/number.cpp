#include<bits/stdc++.h>
using namespace std;
int a[15],b;
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if('0'<=s[i]&&s[i]<='9')a[s[i]-'0']++;
    }
    for(int i=9;i>=0;i--)
    {
        if(i==0&&b==0)
        {
            cout<<0;
            return 0;
        }
        b+=a[i];
        for(int j=1;j<=a[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
