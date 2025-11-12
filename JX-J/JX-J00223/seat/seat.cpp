#include <bits/stdc++.h>
using namespace std;
int a[105];
int ans,pos,ans1,ans2;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        ans==a[1];
    }
    sort(a+1,a+(n*m)+1);
    for(int i=1;i<=n*m;i++)
    {
        if(a[i]==ans)
        {
            pos=(n*m)-i+1;
        }
    }
    ans1=pos/n;
    if(pos%n<m)
    ans2=m-(pos%n);
    if(pos%n==0)
    {
        ans2=m;
    }
    cout<<ans1<<" "<<ans2;



    return 0;
}
