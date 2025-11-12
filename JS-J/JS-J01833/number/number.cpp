#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int a[1000006],n=s.size();
    for (int i=0;i<=s.size();i++)
    {
        a[i]=-1;
        if(s[i]<='9'&&s[i]>='0')
            a[i]=s[i]-48;
    }
    sort(a,a+n+1);
    for (int i=n;i>=0;i--)
    {
        if(a[i]!=-1)
            cout<<a[i];
    }
    return 0;
}
