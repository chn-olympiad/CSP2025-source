#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,j,ans,v=1,cup=0,i=1;
    string s;
    cin>>s;
    while('\0')
    {
        if(s[i]=='0')
        a[i]=0,j++;
        else if(s[i]=='1')
        a[i]=1,j++;
        else if(s[i]=='2')
        a[i]=2,j++;
        else if(s[i]=='3')
        a[i]=3,j++;
        else if(s[i]=='4')
        a[i]=4,j++;
        else if(s[i]=='5')
        a[i]=5,j++;
        else if(s[i]=='6')
        a[i]=6,j++;
        else if(s[i]=='7')
        a[i]=7,j++;
        else if(s[i]=='8')
        a[i]=8,j++;
        else if(s[i]=='9')
        a[i]=9,j++;
        i++;
    }
    for(int i=1;i<=j;i++)
    {
        if(a[i+1]<a[i])
        { cup=a[i];
            a[i]=a[i+1];
            a[i+1]=cup;
        }
    }
    for(int i=1;i<=j;i++)
    {
        ans+=a[i]*v;
        v*=10;
    }
    cout<<ans;
    return 0;
}