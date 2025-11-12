#include<bits/stdc++.h>
using namespace std;
int a[5010],n,cnt;
void dfs(int dep,int h,int m,int f){
    if(dep>=3&&h>m*2&&f==1){
        cnt++;
    }
    if(dep>n) return;
    dfs(dep+1,h,m,0);
    if(a[dep]>m) m=a[dep];
    dfs(dep+1,h+a[dep],m,1);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int x=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        x=max(x,a[i]);
    }
    if(x==1){
        long long sum=0;
        for(int i=1;i<=n-2;i++){
            sum+=(n-i)*(n-i-1)/2;
            sum%=998244353;
        }
        cout<<sum;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<cnt;
    return 0;
}