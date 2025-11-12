#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n,a[200],b[101],sum1=0,k=0,l=0,x=0,y=0;
    cin >> m >> n;
    for(int i=1;i<=n*m;i++)
    {
        cin >> a[i];
    }
    k=a[1];
    for(int i=1;i<=n*m;i++)
    {
        b[a[i]]++;
    }
    for(int i=100;i>=1;i--)
    {
        sum1+=b[i];
        if(i==k)
        {
            l=(sum1-(sum1%n))/n;
            if(sum1%n==0 && l%2==1)
            {
                x=l;
                y=n;
            }
            if(sum1%n==0 && l%2==0)
            {
                x=l;
                y=1;
            }
            if(sum1%n!=0 && l%2==1)
            {
                x=l+1;
                y=n-(sum1%n)+1;

            }
            if(sum1%n!=0 && l%2==0)
            {
                x=l+1;
                y=sum1%n;
            }
        }
    }
    cout << x << " " << y;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
