#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[5086],t[5086];
void dfs(int s,int t,int b){

    if(t==n) return;
    for(int i=t+1;i<=n;i++){
        dfs(s+a[i],i,b);
    }
    if(a[b]<s&&t>3) ans++;
    return;
}
int main(){

    freopen("polygon.in","r",stdin);

    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i];
    }
    sort(t,t+n+1);
    for(int i=n;i>=1;i--){
        a[n-i+1]=t[i];
    }
    for(int i=1;i<=n;i++){
        dfs(0,1,i);
    }
    cout<<ans%998244353;
return 0;
}
