#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,ans=0,a[100010],b[100010],c[100010];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n/2;i++){
            ans+=a[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}
