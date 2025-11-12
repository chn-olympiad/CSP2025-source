#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("numder.out","w",stdout);
    int i,as=0;
    string s;
    cin>>s;
    int a[1000000];
    for(i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[as]=s[i]-48;
            as++;
        }
    }
    sort(a,a+as);
    for(i=as-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
