#include<bits/stdc++.h>
using namespace std;
int n,sum=0,num[5005];
const int Q=998244353;
void dfs(int maxn,int h,int now,int l){
    if(h>maxn && l>=3){
        int s=1;
        for(int i=1;i<=i-1;i++){
            s*=2;
        }
        sum+=s;
        return;
    }
    if(now==1){
        return;
    }
    for(int i=now-1;i>=1;i--){
        dfs(maxn,h+num[i],i,l+1);
        dfs(maxn,h,i,l);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(&num[1],&num[n+1]);
    for(int i=n;i>=3;i--){
        dfs(num[i],num[i],i,1);
    }
    cout<<sum%Q;
    return 0;
}
