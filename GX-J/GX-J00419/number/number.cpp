#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int lon=s.size(),ans=0,a[lon];
    for(int i=0;i<=lon-1;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[ans+1]=s[i]-'0';
            ans+=1;
        }
    }
    sort(a+1,a+ans+1);
    for(int i=ans;i>=1;i--)
    {
        cout<<a[i];
    }
    return 0;
}
