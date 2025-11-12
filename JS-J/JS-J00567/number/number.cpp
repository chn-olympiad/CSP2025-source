#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int ans1=0,ans2=0;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            ans1++;
            a[ans1-1]=int(s[i]-'0');
            if(s[i]!='0')
            {
                ans2++;
            }
        }
    }
    if(ans2==0)
    {
        cout<<0;
        return 0;
    }
    sort(a,a+ans1);
    for(int i=ans1-1;i>=0;i--)
    {
        cout<<a[i];
    }
    return 0;
}
