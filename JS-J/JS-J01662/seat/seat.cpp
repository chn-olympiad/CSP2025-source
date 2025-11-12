#include <bits/stdc++.h>
using namespace std;
int m,n;
int cnt;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int a;
    cin>>a;
    for(int i=2;i<=n*m;i++)
    {
        int x;
        cin>>x;
        if(x>a) cnt++;
    }
    int ans=cnt%(2*n)+1;
    int rm=cnt/n;
    if(cnt*n!=0) rm++;
    if(ans>n) cout<<rm<<" "<<2*n-ans+1;
    else cout<<rm<<" "<<ans;
    return 0;
}
