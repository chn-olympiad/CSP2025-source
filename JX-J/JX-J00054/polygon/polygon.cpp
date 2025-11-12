#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long cnt=0;
bool t[5005];
void dfs(int id,int maxn,int all,int sum){
    if(id==n+1){
        return;
    }
    if(all>(maxn*2) && sum>2){
        cnt=(cnt+1)%998244353;
    }
    for(int i=id;i<=n;i++){
        if(t[i]==1)return;
        t[i]=1;
        dfs(id+1,max((long long)maxn,a[i]),all+a[i],sum+1);
        t[i]=0;
        dfs(id+1,maxn,all,sum);
    }
    return;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,greater<int>());
    dfs(1,a[1],0,0);
    cout<<cnt%998244353;
    return 0;
}
