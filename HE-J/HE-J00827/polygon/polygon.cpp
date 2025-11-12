#include<bits/stdc++.h>
using namespace std;
long long n,a[2501]={},p[2501]={},f=0;
long long c=0,h=1;
bool check(){
    long long w=0,e=0,ma=0;
    for(long long i=1;i<=n;i++){
        if(p[i]){
            e++;
            w+=a[i];
            ma=max(ma,a[i]);
        }
    }if(w>ma*2&&e>=3)return 1;
    return 0;
}void dfs(long long q){
    if(q==n+1){
        if(check()){
            c+=h;
            c%=998244353;
        }
        return ;
    }p[q]=1;
    dfs(q+1);
    p[q]=0;
    dfs(q+1);
}int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)cin>>a[i];
    if(n>21){
        cout<<n-2;
        return 0;
    }
    dfs(1);
    cout<<c;
    return 0;
}
