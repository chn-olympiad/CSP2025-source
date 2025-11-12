#include<bits/stdc++.h>
using namespace std;
long long a[1001],i,n,m,l,k,y,hang=1,number=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    cin>>l;
    for(i=1;i<=n*m-1;i++)
    {
        cin>>a[i];
    }
     for(i=1;i<=n*m-1;i++)
    {
        for(y=i+1;y<=m*n-1;y++)
        {
            if(a[i]<a[y])
            {
                k=a[i];
            a[i]=a[y];
                a[y]=k;
            }
        }
    }
    for(i=1;i<=n*m-1;i++)
    {
        if(l>a[i])
        {
            l=i;
            break;
        }
        else if(i==n*m)
        {
            l=i;
        }


    }
    for(i=1;i<=n;i++)
    {
        if(i%2==1)
        {
            hang=1;
            number++;
           if(number==l)
                {
                    cout<<i<<" "<<1;
                    return 0;
                }
            for(y=2;y<=m;y++)
            {

                hang++;
                number++;
                if(number==l)
                {
                    cout<<i<<" "<<hang;
                    return 0;
                }

            }
        }
        if(i%2==0)
        {
            hang=m;
            number++;
            if(number==l)
                {
                    cout<<i<<" "<<m;
                    return 0;
                }

            for(y=m;y>1;y--)
            {
                number++;
                hang=hang-1;
                if(number==l)
                {
                    cout<<i<<" "<<hang;
                    return 0;
                }


            }
        }
    }
        return 0;
}
