#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+6;
ll b[N];
ll ans=0;
ll t;
ll n,a[N][4];
ll club(int i,int x1,int x2,int x3){
    if(i==n+1){
        ans=max(ans,b[i]);
        return b[i];
    }
    if(x1<n/2){
        b[i+1]=b[i]+a[i][1];
        club(i+1,x1+1,x2,x3);
    }
    if(x2<n/2){
        b[i+1]=b[i]+a[i][2];
        club(i+1,x1,x2+1,x3);
    }
    if(x3<n/2){
        b[i+1]=b[i]+a[i][3];
        club(i+1,x1,x2,x3+1);
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];}
        b[0]=0;
        club(0,0,0,0);
    cout<<ans<<endl;
    }
    return 0;
}
