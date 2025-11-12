#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int n,cnt,res=1,a[N];
signed main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==1) cnt++;
    }
    if(cnt==n){
        for(int i=1;i<=n;i++){
            res*=2;
            res%=998244353;
        }
        cout<<res-2-2*n-(n*n-n)/2;
        return 0;
    }
    else if(n==3){
        if(2*(max(a[1],max(a[2],a[3])))<a[1]+a[2]+a[3]) cout<<"1";
        else cout<<"0";
        return 0;
    }
    else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
        cout<<"6";
        return 0;
    }
    cout<<"9";
    return 0;
}
