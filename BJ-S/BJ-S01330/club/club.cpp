#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
    int x,y,z;
    int o;
}a[1000009];
int z[1000009];
inline void _main(){
    int n;
    cin>>n;
    int ans;
    ans=0;
    int  a1,a2,a3;
    a1=a2=a3=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y>>a[i].z;
        ans+=max(a[i].x,max(a[i].y,a[i].z));
        if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
            a1++;
            a[i].o=1;
        }else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
            a2++;
            a[i].o=2;
        }else{
            a3++;
            a[i].o=3;
        }
    }
    if(a1<=n/2&&a2<=n/2&&a3<=n/2){
        cout<<ans<<endl;
        return;
    }
    int inn;
    inn=0;
    int k;
    k=max(a1,max(a2,a3))-n/2;
    if(a1>n/2){
        for(int i=1;i<=n;i++){
            if(a[i].o==1){
                z[++inn]=-(a[i].x+a[i].y+a[i].z)+2*max(a[i].x,max(a[i].y,a[i].z))+min(a[i].x,min(a[i].y,a[i].z));
            }
        }
    }
    if(a2>n/2){
        for(int i=1;i<=n;i++){
            if(a[i].o==2){
                z[++inn]=-(a[i].x+a[i].y+a[i].z)+2*max(a[i].x,max(a[i].y,a[i].z))+min(a[i].x,min(a[i].y,a[i].z));
            }
        }
    }
    if(a3>n/2){
        for(int i=1;i<=n;i++){
            if(a[i].o==3){
                z[++inn]=-(a[i].x+a[i].y+a[i].z)+2*max(a[i].x,max(a[i].y,a[i].z))+min(a[i].x,min(a[i].y,a[i].z));
            }
        }
    }
    sort(z+1,z+1+inn);
    for(int i=1;i<=k;i++){
        ans-=z[i];
    }
    cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        _main();
    }
    return 0;
}
