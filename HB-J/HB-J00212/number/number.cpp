#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100000];
    char b[100000];
    int m=0,x=1;
    while(cin>>a[x])
    {
        x++;
    }
    //for(int i=1;i<x;i++)
    //{
    //    cout<<a[i];
     //   continue;
    //}
    x-=1;
    for(int i=1;i<=x;i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            m++;
            b[m]=a[i]-'0';
        }
    }
    if(m==1)
    {
        printf("%c",b[1]);
        return 0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<m;j++)
        {
            if((b[j]-'0')<(b[j+1]-'0'))
            swap(b[j],b[j+1]);
        }
    }
    else{
        for(int i=1;i<=m;i++)
        {
            printf("%d",int(b[i]-'0'));
        }
    }
    return 0;
}
