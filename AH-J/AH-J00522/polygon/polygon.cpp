#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int ans;
void dfs(int m,int he,int last){
    if(m>=n){
        if(he>last*2)ans=(ans+1)%998244353;
        return;
    }dfs(m+1,he+a[m],a[m]);
    dfs(m+1,he,last);
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }sort(a,a+n);
    dfs(0,0,0);
    cout<<ans;
    return 0;
}
