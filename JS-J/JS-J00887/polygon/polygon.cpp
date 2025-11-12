#include <bits/stdc++.h>
using namespace std;
int a[1111],n,d,num;
void dfs(int x,int tot){
    if(x>=3 &&a[x]<tot)
        num++;
    if(x==n)return;
    for(int i=x+1;i<=n;i++){
    dfs(i,tot+a[x]);}
    return;
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<3)cout<<0;
    if(n==3){
        d=max(a[1],max(a[2],a[3]));
        d*=2;
        if(a[1]+a[2]+a[3]>d)cout<<1;
        else cout<<0;
    }
    if(n>3 &&n<=1000){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)dfs(i,0);
        cout<<num%998244353;}
    return 0;
}
