#include <bits/stdc++.h>
using namespace std;
int n,m,a[1010],ans,x;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
    }
    ans=a[1];
    x=n*m;
    sort(a+1,a+1+x);
    for(int i=1;i<=m;i++)
    {
        if(i%2==1)
        {
            for(int l=1;l<=n;l++)
            {
                if(a[x]==ans)
                {
                    cout<<i<<" "<<l;
                    return 0;
                }
                x--;
            }
        }
        else
        {
            for(int l=n;l>=1;l--)
            {
                if(a[x]==ans)
                {
                    cout<<i<<" "<<l;
                    return 0;
                }
                x--;
            }
        }
    }
    return 0;
}
