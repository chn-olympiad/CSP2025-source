#include <bits/stdc++.h>
using namespace std;
int m,n,grade,a[111111];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    cin>>a[1];
    grade=a[1];
    for(int i=2;i<=m*n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n*m);
    for(int j=1;j<=n*m;j++)
    {
        if(grade==a[j])
        {
            if(j%n==0)
                cout<<j/n<<" ";
            else
                cout<<j/n+1<<" ";
            if(j%(2*n)<=n)
            {
                if(j%n==0)
                    cout<<n;
                else
                    cout<<n-j+1;
            }
            else
            {
                if(j%(2*n)==0)
                    cout<<1;
                else
                    cout<<2*n-j+1;
            }
            return 0;
        }
    }
}
