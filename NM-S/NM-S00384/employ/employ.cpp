#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
bool light[505];
int ans[505];
int sum=0;
void dfs(int k){
    for(int i=1;i<=n;i++){
        if(light[i]==1) continue;
        light[i]=1;
        ans[k]=i;
        dfs(k+1);
        light[i]=0;
    }
    if(k==n){
        sum++;
    }
    return ;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1);
    cout<<sum%998244353;
    return 0;
}
