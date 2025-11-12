#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    long long a[1000000],b=0,tj=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[b]=s[i]-'0';
            tj++;
            b++;
        }
    }
    for(int i=0;i<tj;i++)
    {
        for(int j=i+1;j<tj;j++)
        {
            if(a[i]<a[j])
            {
                swap(a[i],a[j]);
            }
        }
    }
    for(int i=0;i<tj;i++)
    {
        cout<<a[i];
    }
    return 0;
}
