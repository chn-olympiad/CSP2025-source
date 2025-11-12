#include<bits/stdc++.h>
using namespace std;
int n,m,xa,a[105];bool r=0;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    xa=a[1];
    stable_sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[(i-1)*n+j]==xa)
            {
                if(r==0)cout<<i<<' '<<j<<endl;
                else cout<<i<<' '<<n-j+1<<endl;
                return 0;
            }
        }
        r=1-r;
    }
    return 0;
}
