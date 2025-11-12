#include<bits/stdc++.h>
using namespace std;
string a;
int b[]={0};
bool s(int c,int z)
{
    return c>z;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    int x=a.size(),cnt=0;
    for(int i=0;i<x;i++)
    {
        if('0'<=a[i]&&a[i]<='9')
        {
            b[++cnt]=a[i]-'0';
        }
    }
    sort(b+1,b+x+1,s);
    if(b[1]==0)
    {
        cout<<"0";
    }else
    {
        for(int i=1;i<=cnt;i++)
        {

            printf("%d",b[i]);
        }
    }
    return 0;
}
