#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","w",stdin);
    freopen("number.out","r",stdout);
    int a[101],b,t=1,x=0,y;
    bool c;
    cin>>b;
    c=b;
    for(int i=1;i<=100;i++) a[i]=0;
    while(c!=0||c==' ')
    {
        if(b<10)
        {
            a[t]=b;
            t++;
        }
        cin>>b;
        c=b;
    }
    for(int i=1;i<=t-1;i++)
    {
        for(int j=i;j<=t-1;j++)
        {
            if(a[j-1]<a[j])
            {
                swap(a[j-1],a[j]);
            }

        }
    }
    for(int i=1;i<=t;i++)
    {
        cout<<a[i];
    }
    return 0;
}
