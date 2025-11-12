#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=1;
    cin>>n>>m;
    int a,aa;
    cin>>aa;
    for(int i=1;i<=n*m;i++)
    {
        cin>>a;
        if(a>aa) cnt++;
    }
    int ans1=(cnt-1)/n+1;
    cout<<ans1<<" ";
    if(ans1%2==1) cout<<(cnt-1)%n+1;
    else cout<<n-cnt%n+1;
    return 0;
}
