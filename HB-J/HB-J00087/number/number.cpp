#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100000],f=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]<='9'&&s[i]>='0')
        {
            a[i]=s[i]-'0';f++;
        }
    }
    sort(a,a+f);
    for(int i=f-1;i>=0;i--)
    {
        if(a[0]==0)cout<<"0";
        else cout<<a[i];
    }
    return 0;
}
