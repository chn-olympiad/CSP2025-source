#include<bits/stdc++.h>
using namespace std;
int a1[5010],i,j=1,b,c,n,t=1,w1,w2,a2[5010],d,g,m,w3,k;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)
    {
       cin>>a1[i];
         d+=a1[i];
    }
    while(t<=n)
    {
        for(i=1;i<=n;i++)
        {
            if(a1[i]>w1)
            {
                w1=a1[i];
                w2=i;
            }
        }
        a2[j]=w1;
        a1[w2]=0;
        j++;
        t++;
        w1=0;
        w2=0;
    }
    if(a2[n]+a2[n-1]>a2[n-2])
        c++;
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
