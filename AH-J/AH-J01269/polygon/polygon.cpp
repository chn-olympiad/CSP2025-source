#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
int ans;
void dfs(int x,int sum,int last,int have,int used){
    if(sum>2*last&&have>=3&&used){
        ans++;
        ans=ans%998244353;
        used=0;
    }
    if(x>=n){
        return;
    }
    dfs(x+1,sum+a[x],a[x],have+1,1);
    dfs(x+1,sum,last,have,used);

    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0,0);
    cout<<ans;
    return 0;
}
