#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,g,rk,r,c;
int a[N];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    g=a[1];
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==g){
            rk=i;
            break;
        }
    }
    while(rk>=n) r++,rk-=n;
    if(rk==0){
        cout<<r<<' ';
        if(r%2==1) cout<<n<<'\n';
        else cout<<1<<'\n';
        return 0;
    }
    r++;
    if(r%2==1) c=rk;
    else c=n-rk+1;
    cout<<r<<' '<<c<<'\n';
    return 0;
}
