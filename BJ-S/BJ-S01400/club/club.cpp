#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n,k;
ll a[100005],b[100005],c[100005];
ll ans=-1;
bool fi=1;
ll dfs(ll sum,ll numa,ll numb,ll numc,ll i){
    if(i==n+1){
        ans=max(ans,sum);
        return 0;
    }
    if(numa<k){
        dfs(sum+a[i],numa+1,numb,numc,i+1);
    }
    if(numb<k){
        dfs(sum+b[i],numa,numb+1,numc,i+1);
    }
    if(numc<k){
        dfs(sum+c[i],numa,numb,numc+1,i+1);
    }
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        k=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(b[i]!=0||c[i]!=0)fi=0;
        }
        if(fi){
            ans=0;
            sort(b+1,b+1+n);
            for(int i=n;i>n/2;i--){
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        }
        if(fi)
        dfs(0,0,0,0,1);
        cout<<ans<<endl;
        ans=-1;
    }
    return 0;
}