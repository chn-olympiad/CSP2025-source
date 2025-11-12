#include<bits/stdc++.h>
using namespace std;
int ans,xm,cnt,m,n;
int main(){
    std::ios::sync_with_stdio(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>xm;
    for(int i=2;i<=n*m;i++){
        int o;
        cin>>o;
        if(o>xm) cnt++;
    }
    cnt;
    cout<<cnt/n+1<<' ';
    if((cnt/n)%2==0) cout<<cnt%n+1;
    else cout<<n-cnt%n;
    return 0;
}

