#include<bits/stdc++.h>
using namespace std;
int n,a[6005],ans;
void dfs(int c,int k,int max0){
    for(int i=k;i<=n;i++){
        if(c>=3)if(a[i]<max0)ans++;
        dfs(c+1,i+1,max0+a[i]);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    dfs(1,1,0);
    cout<<ans;
    return 0;
}
