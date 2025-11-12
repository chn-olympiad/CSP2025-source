#include<iostream>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mc=0,xr,l,h;
    int a[105];
    int b[105][105];
    cin>>n>>m;
    /*
    for(int i=1;i<=ml;i++)
    {

        for(int j=1;j<=nh;i++)
        {
            if(v=1)
                h++;
            else
                h--;
            a[h][l]=s;
            s++;

        }
        l++;
        h++;
        if(v=0)
            v=1;
        else
            v=0;
    }
    */
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    xr=a[1];
    for(int i=1;i<=n*m;i++)
    {
        for(int j=1;j<=n*m;j++)
        {
            if(a[j]<a[j+1])
            {
                //cout<<a[j]<<" "<<a[j+1]<<endl;
                swap(a[j],a[j+1]);
            }

        }
    }
    /*
    for(int i=1;i<=n*m;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=1;i<=n*m;i++)
    {
        mc++;
        if(a[i]==xr)
            break;
    }
    if(mc%n==0)
    {
        l=mc/n;
        cout<<l;
    }

    else
    {
        l=mc/n+1;
        cout<<l;
    }
    if(l%2==1)
    {
        mc%=n;
        if(mc==0)
            cout<<" "<<n;
        else
            cout<<" "<<mc;
    }
    else
    {
        mc%=n;
        if(mc==0)
            cout<<" "<<1;
        else
            cout<<" "<<n-mc+1;
    }
    return 0;
}
