#include<bits/stdc++.h>
using namespace std;
int n,a[50002],ans,maxn;
void dfs(int now,int num,int sum,int max2){
    if(now>n){
        if(num>2){
            if(sum>max2*2)++ans;
        }
        return ;
    }
    dfs(now+1,num,sum,max2);
    dfs(now+1,num+1,sum+a[now],max(max2,a[now]));
    return ;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>maxn)maxn=a[i];
    }
    if(maxn==1){
        int sum=1;
        for(int i=1;i<=n;i++)sum=(sum*2)%998244353;
        cout<<sum-n*(n+1)/2-1;
        return 0;
    }
    dfs(1,0,0,0);
    cout<<ans;
    return 0;
}