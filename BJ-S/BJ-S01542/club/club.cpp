#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+10;
ll ans=-1;
ll n,a[N][5];
void dfs(ll st,ll fz[5],ll q){
    if(fz[1]>=n/2||fz[2]>=n/2||fz[3]>=n/2||st>n){
        r++;
        ans=max(ans,q);
        return;
    }
    for(int i=1;i<=3;i++){
        fz[i]++;
        dfs(st+1,fz,q+a[st][i]);
        fz[i]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
        ans=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        ll t[5]={};
        dfs(1,t,0);
        cout<<ans<<endl;
    }
    return 0;
}