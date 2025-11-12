#include <bits/stdc++.h>
using namespace std;
long long n,m,a[110],x,l,r,ans,y;
bool cmp(long long p,long long q){
    return p>q;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    l=1,r=n*m;
    for(int i=1;i<=r;i++){
        cin>>a[i];
    }
    x=a[1];
    sort(a+1,a+r+1,cmp);
    //for(int i=1;i<=r;i++) cout<<a[i]<<" ";
    while(1){
        ans=(l+r)/2;
        if(a[ans]>x){
            l=ans+1;
        }
        else if(a[ans]<x){
            r=ans-1;
        }
        else{
            //cout<<ans<<"\n";
            break;
        }
        if(r<l){
            break;
        }
    }
    cout<<(ans+n-1)/n<<" ";
    y=ans%(2*n);
    if(y<=n) cout<<y;
    else cout<<n-y+n+1;
    return 0;
}
