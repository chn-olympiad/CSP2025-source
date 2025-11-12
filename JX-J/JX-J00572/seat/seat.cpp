#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    int n,m,c=0;
    cin>>n>>m;
    int a[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if(a[0][0]<=a[i][j])
            {
                c++;
            }
        }

    }
    if(c%n!=0)
    {
        cout<<c/n+1<<" ";
        for(int i=1;i<=n;i+=2)
        {
            if(c=i*n+1)
            {
                cout<<n;
            }
        }

    }
    else{
        cout<<c/n<<" ";
        if(c/n%2==1)
        {
            cout<<c/n;
        }
        else
        {
            cout<<1;
        }
    }



    return 0;
}
