#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a[1000010]={0},cnt=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[++cnt]=s[i]-48;
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        for(int j=i+1;j<=cnt;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
