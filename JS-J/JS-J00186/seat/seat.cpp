#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int p,q,cnt=1,a[11][11];
    cin>>p;
    for(int i=2;i<=n*m;i++){
        cin>>q;
        if(q>p){
            cnt++;
        }
    }
    int s=(cnt-1)/n,t=(cnt-1)%n,r;
    cout<<s+1<<' ';
    if(s%2==0){
        r=t+1;
        cout<<r;
    }
    else{
        r=n-t;
        cout<<r;
    }
    return 0;
}
