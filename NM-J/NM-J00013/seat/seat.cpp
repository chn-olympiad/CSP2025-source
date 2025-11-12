#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int a,n,num,m,v;
    cin>>n>>m;
    a=n*m;
    int s[a];
    for(int i=0;i<a;i++)
    {
        cin>>s[i];
    }
    num=s[0];
    sort(s,s+a);
    for(int i=a-1;i>=0;i--)
    {
        v++;
        if(s[i]==num)
        {
            break;
        }
    }
    int c,r;
    c=v/n;
    v-=n*c;
    if(v!=0)
    {
        if(c%2==0)
        {
            r=v;
        }
        else
        {
            r=n-v+1;
        }
        c++;
    }
    else
    {
        if(c%2==0)
        {
            r=1;
        }
        else
        {
            r=n;
        }
    }
    cout<<c<<" "<<r<<endl;
    return 0;
}
