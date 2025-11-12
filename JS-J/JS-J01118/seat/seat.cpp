#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[105];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(n<=1&&m<=1){
        int x;
        cin>>x;
        cout<<1<<' '<<1;
        return 0;
    }
    else if(n<=1&&m>1){
        for(int i=1;i<=m;i++) cin>>a[i];
        int v=a[1];
        sort(a+1,a+m+1,greater<int>());
        for(int i=1;i<=m;i++) if(a[i]==v) cout<<i<<' '<<1;
        return 0;
    }
    else if(n>1&&m<=1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int v=a[1];
        sort(a+1,a+n+1,greater<int>());
        for(int i=1;i<=n;i++) if(a[i]==v) cout<<1<<' '<<i;
        return 0;
    }
    else if(n==2&&m==2){
        for(int i=1;i<=4;i++) cin>>a[i];
        int v=a[1];
        sort(a+1,a+4+1,greater<int>());
        if(v==a[1]) cout<<1<<' '<<1;
        else if(v==a[2]) cout<<1<<' '<<2;
        else if(v==a[3]) cout<<2<<' '<<2;
        else cout<<2<<' '<<1;
        return 0;
    }
    else return 0;
}
