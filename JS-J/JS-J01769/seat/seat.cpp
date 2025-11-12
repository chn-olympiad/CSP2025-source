#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++)
    {
        cin >> a[i];
    }
    int x = a[1],xi,ans1,ans2;
    sort(a+1,a+n*m+1);
    for(int i = 1;i <= n*m;i++)
    {
        if(a[i]==x)
        {
            xi = i;
            break;
        }
    }
    xi = n*m-xi+1;
    ans1 = xi/n;
    if(xi%n!=0)
    {
        ans1++;
    }
    if(ans1%2==0)
    {
        ans2 = n-((xi-1)%n+1)+1;
    }
    else
    {
        ans2 = (xi-1)%n+1;
    }
    cout << ans1 << " " << ans2;
    return 0;
}
