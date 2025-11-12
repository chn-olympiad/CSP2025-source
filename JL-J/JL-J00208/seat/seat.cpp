#include <bits/stdc++.h>
using namespace std;
int n,m,a[110],ans;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    freopen("seat.in","w",stdin);
    freopen("seat.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a[i];
        ans=a[1];
    }
    sort(a+1,a+1+n*m,cmp);
    for(int i=1,j=1;i<=n,j<=n;)
    {
        if(a[i]!=ans&&i!=n&&j%2!=0)
            i++;
        else if(a[i]!=ans&&i==n&&j!=m)
            j++;
        else if(a[i]!=ans&&i!=n&&j%2==0)
            i--;
        else if(a[i]==ans)
        {
            cout<<j<<" "<<i;
            return 0;
        }
    }
    return 0;
}
