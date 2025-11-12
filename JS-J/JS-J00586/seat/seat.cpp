#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],x,cnt=1,ans1,ans2;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    x=a[1];
    for(int i=1;i<=n*m;i++)
        if(a[i]>x)
            cnt++;
    ans1=(cnt-1)/n+1;
    ans2=(cnt-1)%n+1;
    if(ans1%2==0)
        ans2=n-ans2+1;
    cout<<ans1<<" "<<ans2<<'\n';
    return 0;
}
