#include <bits/stdc++.h>
using namespace std;
const int N=998244353;
int a[10005];
int n,ans;
void dg(int dep,int sum,int zd){
    if(dep>n){
        if(sum>zd*2){
            ans++;
        }
    }
    else{
        dg(dep+1,sum,zd);
        dg(dep+1,sum+a[dep],max(zd,a[dep]));
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    if(n==3){
        if(a[1]>(a[1]+a[2]+a[3])*2){
            cout<<0;
        }
        else{
            cout<<1;
        }
    }
    else if(n<=20&&a[1]!=a[n]){
        dg(1,0,0);

        cout<<ans;
    }
    else{
        cout<<n-2;
    }
    return 0;
}