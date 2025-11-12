#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[10000],o;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        if(i==1)
        {
            o=a[i];
        }
    }
    for(int i=1;i<=n*m;i++)
    {

        for(int j=i;j<=n*m;j++)
        {
            if(a[j]<a[j+1])
            {
                int k=a[j-1];
                a[j-1]=a[j];
                a[j]=k;
            }
        }
    }
    for(int i=1;i<=n*m;i++)
    {

        if(a[i]==o)
        {

            if(i<=n)
            {

                cout<<'1'<<" "<<n;
            }
            else
            {
                if((i/n+1)%2==0)
                {

                    cout<<i/n+1<<' '<<n+1-(i-i/n*n);
                }
                else
                {

                    cout<<i/n+1<<' '<<i-i/n*n;
                }
            }
            break;
        }
    }
    return 0;
}


