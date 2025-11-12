#include <bits/stdc++.h>
using namespace std;
bool c(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,k,a[105];
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+n*m+1,c);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==k)
        {
            int ans=(i-1)/m+1;
            cout<<ans<<" ";
            if(ans%2==0)
            {
                cout<<1+n-(i-(ans-1)*n);
            }
            else
            {
                cout<<i-(ans-1)*n;
            }
            return 0;
        }
    }
}
