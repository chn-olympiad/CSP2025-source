#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    for(int i=2;i<=n*m;i++)
        if(a[i]>a[1])
            cnt++;
    if(cnt/n&1)
        cout<<cnt/n+1<<" "<<n-cnt%n+1;
    else
        cout<<cnt/n+1<<" "<<cnt%n;
    return 0;
}
