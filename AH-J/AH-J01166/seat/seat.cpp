#include<bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {

        cin>>a[i];

    }
    int s=a[1];
    int c=1;
    for(int i=1;i<=m*n;i++)
    {
        if(s<a[i])
            c++;
    }
    if(c<=n)
    {
        cout<<1<<" "<<c;
    }
    else
    {
        if(c/n!=0&&(c/n+1)%2==0)
        {
            cout<<c/n+1<<" "<<n+1-c%n;

        }
        else if(c/n!=0&&(c/n+1)%2!=0)
        {
            cout<<c/n+1<<" "<<c%n;
        }
        else if(c%n==0&&(c/n)%2==0)
        {
            cout<<c/n<<" "<<1;
        }
        else
            cout<<c/n<<" "<<n;

    }
    return 0;

}
