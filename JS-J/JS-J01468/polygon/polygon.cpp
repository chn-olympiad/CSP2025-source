#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,qwe;
    bool flag=true;
    cin>>n;
    int a[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1)
        {
            flag=false;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=n-1;j>=1;j--)
        {
            if(a[j]>a[j+1])
            {
                qwe=a[j];
                a[j]=a[j+1];
                a[j+1]=qwe;
            }
        }
    }
    if(n==3)
    {
        if(a[1]+a[2]>a[3])
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    else if(flag=true)
    {
        int hee=1;
        for(int i=1;i<=n;i++)
        {
            hee*=n;
        }
        int ans=hee,sumqw=0,qwert=3,lin=1;
        while(qwert<=n)
        {
            lin=1;
            for(int i=1;i<=n-qwert;i++)
            {
                lin*=i;
            }
            for(int i=1;i<=qwert;i++)
            {
                lin*=i;
            }
            ans/=lin;
            sumqw+=ans;
            qwert++;
        }
        cout<<sumqw;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
