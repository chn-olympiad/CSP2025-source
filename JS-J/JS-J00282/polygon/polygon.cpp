#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],ans;
void dfs(int h,long long s,long long m,int i){
    if(h==n||i>n){
        if(s>0){
            ans++;
            ans%=998244353;
        }
        return;
    }
    long long ns;
    if(a[i]>m){

        dfs(h+1,s-2*(a[i]-m)+a[i],a[i],i+1);
    }
    else{
        dfs(h+1,s+a[i],m,i+1);
    }
    dfs(h,s,m,i+1);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    dfs(0,0,0,1);
    cout<<ans%998244353;
    return 0;
}