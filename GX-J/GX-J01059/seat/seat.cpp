#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a[101],b=1,c=1,d=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }

    for(int i=2;i<=n*m;i++)
    {
        if(b%2!=0)
        {
            if(a[1]<a[i]&&c<=n)
            {

                c++;
            }
            if(a[1]<a[i]&&c==n)
            {
                c=n;
                d++;
            }
        }
        else
        {
            if(a[1]<a[i]&&c>=1)
            {
                c--;
            }
            if(a[1]<a[i]&&c==1)
            {
                c=1;

            }
        }
        b++;
    }
    cout<<d<<" "<<c;
    return 0;
}

