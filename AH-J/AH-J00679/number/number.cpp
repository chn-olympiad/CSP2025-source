#include <bits/stdc++.h>
using namespace std;
int a[100010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    bool h=false;
    int j=0,b=-1,n;
    for(int i=0;i<=s.size();i++)
    {

        if(isdigit(s[i]))
        {

            a[j]=s[i]-'0';
            j++;
        }
    }
    for(int i=0;i<j;i++)
    {
        if(a[i]!=0)
        {
            h=true;
            break;
        }
    }
    if(h==false)
    {
        cout<<0;
        return 0;
    }
    h=true;
    while(h)
    {
        for(int k=0;k<j;k++)
        {
            if(a[k]>=b)
            {
                b=a[k];
                n=k;
            }
        }
        a[n]=-5;
        cout<<b;
        b=-1;
        h=false;
        for(int i=0;i<j;i++)
        {
            if(a[i]>=0)
            {
                h=true;
                break;
            }
        }
    }

    return 0;
}
