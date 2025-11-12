#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
//map<int,int> f[5005];
int dfs(int x,int sum,int cnt,int maxn){
//    cout<<f[x][sum]<<" ";
    int ans=0;
    if(sum>maxn*2)ans=1;
//    if(f[x][sum])return f[x][sum];
    for(int i=x+1;i<=n;i++){
        ans+=dfs(i,sum+a[i],cnt+1,max(maxn,a[i]));
    }
//    f[x][sum]=ans;
//    cout<<x<<" "<<sum<<' '<<cnt<<' '<<ans<<"\n";
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=1000;j++){
//            if(f[i][j]!=0){
//                cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
//            }
////            cout<<1;
//        }
//    }
    cout<<dfs(0,0,0,0);
    return 0;
}
