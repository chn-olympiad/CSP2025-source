#include<bits/stdc++.h>
using namespace std;
int z=1;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    int t;
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            cin>>t;
            if(t>k)
            {
                z++;
            }
        }
    }
    if(z%n==0)
    {
        if((z/n+1)%2==0)
        {
            cout<<z/n<<" "<<m;
        }else{
            cout<<z/n<<" "<<1;
        }
    }else{
        if((z/n+1)%2==0)
        {
            cout<<z/n+1<<" "<<m-(z%n)+1;
        }else{
            cout<<z/n+1<<" "<<z%n;
        }
    }

    return 0;
}
