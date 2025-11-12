#include<bits/stdc++.h>
using namespace std;
int n, m, l, p, a[110];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++)
    {
        cin>>a[i];
    }
    l=a[1];
    sort(a+1, a+1+n*m);
    for(int i=n*m; i>=1; i--)
    {
        if(a[i]==l)
        {
            p=n*m-i+1;
            if(p%n!=0)
            {
                if((p/n+1)%2==1)
                {
                    cout<<p/n+1<<" "<<p%n;
                }
                else
                {
                    cout<<p/n+1<<" "<<m-(p%n)+1;
                }
            }
            else
            {
                cout<<p/n<<" "<<n;
            }
        }
    }
    return 0;
}
