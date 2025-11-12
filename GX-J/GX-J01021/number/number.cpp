#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    int a[100],k=0,x=0;
    cin>>s;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]>='1'&&s[i]<='9')
        {
            a[k]=s[i];
            k++;
        }
    }
    for(int i=0;i<a[100];i++)
    {
        if(a[i]<a[i+1])
        {
            x=a[i];
            a[i]=a[i+1];
            a[i+1]=x;
        }
    }
    for(int i=0;i<a[100];i++)
    {
        cout<<a[i];
    }
    return 0;
}
