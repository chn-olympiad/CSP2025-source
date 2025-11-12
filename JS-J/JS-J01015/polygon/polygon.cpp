#include<bits/stdc++.h>
using namespace std;
int a[50001];int ans=0,n;
void work(int dep,int sum,int maxn){
    if(dep>n){
        if(sum>maxn*2)ans++;
        return ;
    }
    work(dep+1,sum,maxn);
    if(maxn<=a[dep])work(dep+1,sum+a[dep],a[dep]);
    if(maxn>a[dep])work(dep+1,sum+a[dep],maxn);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    work(1,0,0);
    cout<<ans;
    return 0;
}
