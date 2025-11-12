#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
long long ans;
bool f[5005];
void dfs(int l,int k,int e,long long sum,int zuida){
    if(k>e){
        if(sum>zuida*2){
            ans++;
            ans%=998244353;
        }
        return;
    }
    for(int i=l;i<=n;i++){
        if(f[i]==0){
            f[i]=1;
            dfs(i+1,k+1,e,sum+a[i],max(a[i],zuida));
            f[i]=0;
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=3;i<=n;i++){
        dfs(1,1,i,0,0);
    }
    cout<<ans%998244353;
    return 0;
}
