#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100001][4]={};
ll n,cnt=0,ans=-1;
ll sum[3]={};
void dfs(int x){
    for(int i=1;i<=3;i++){
        if(sum[i]<n/2){
            sum[i]++;
            cnt+=a[x][i];
            dfs(x+1);
            ans=max(ans,cnt);
            cnt-=a[x][i];
            sum[i]--;
        }
    }
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ll_;cin>>_;
    while(_--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }
        dfs(1);
        cout<<ans<<" ";
        ans=-1,cnt=0;
        sum[1]=0;
        sum[2]=0;
        sum[3]=0;

    }
    return 0;

}
