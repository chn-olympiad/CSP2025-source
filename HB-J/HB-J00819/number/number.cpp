#include<bits/stdc++.h>
using namespace std;
int a[10],b=0;
int main()
{   freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {   if(s[i]>='0' and s[i]<='9')
            a[int(s[i]-'0')]++;
    }
    for(int i=9;i>0;i--)
        if(a[i]>0)
        {   b=1;
            for(int j=1;j<=a[i];j++)
                cout<<i;
        }
    if(b==1)
        for(int i=1;i<=a[0];i++)
            cout<<0;
    else if(a[0]!=0)
        cout<<0;
    return 0;
}
