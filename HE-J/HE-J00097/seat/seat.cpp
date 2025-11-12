#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main()
{

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m, n;
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
    {
        cin>>a[i];
    }
    int r=a[0],j=0;
    sort(a,a+(n*m));
    for(int i=m*n-1;i>=0;i--)
    {

        if(a[i]==r)
        {
            j=n*m-i;
            break;
        }
    }
    if(j%n==0)
    {
        if((j/n)%2==0)
        {
            cout<<j/n<<" "<<1;
        }
        else
        {
            cout<<j/n<<" "<<n;
        }
    }
    else
    {
        if((j/n+1)%2==0)
        {
            cout<<j/n+1<<" "<<n-(j%n)+1;
        }
        else
        {
            cout<<j/n+1<<" "<<j%n;
        }
    }
}

