#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],max1,b[4],c,d[100000];
void f(int k)
{
    if(k>n)
    {
        int sum1=0;
        for(int i=1;i<=n;i++)
        {
            sum1+=d[i];
        }
        if(sum1>=max1)
        {
            max1=sum1;
        }
    }
    for(int i=1;i<=3;i++)
    {
        if(b[i]<c)
        {
            d[k]=a[k][i];
            b[i]++;
            k++;
            f(k);
            k--;
            d[k]=0;
            b[i]--;
        }

    }
}
int main()
{
    freopen("club.in","w",stdin);
    freopen("club.out","r",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        c=n/2;
        for(int i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        max1=-1;
        b[1]=0;
        b[2]=0;
        b[3]=0;
        f(1);
        cout<<max1;
    }
}
