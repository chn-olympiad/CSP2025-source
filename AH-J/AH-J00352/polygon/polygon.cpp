#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
const int M=998244353;
int n,a[5005];
long long ans;
void dfs(int id,int sum,int mx,int k){
    if(sum>mx*2&&k>=3){
        ans++;
        ans%=M;
    }
    if(id>n-1){
        return ;
    }
    int c=max(mx,a[id]);
    dfs(id+1,sum+a[id],c,k+1);
    dfs(id+1,sum,mx,k);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0,0,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
