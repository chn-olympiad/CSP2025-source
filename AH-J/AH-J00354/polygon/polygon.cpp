#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5005];
int cnt;
void dfs(int t,int maxn,int sum,int step){
    if(t>=3&&sum>maxn*2){
        cnt++;
    }
    if(step>n){
        return ;
    }
    for(int i=step+1;i<=n;i++){
        dfs(t+1,max(maxn,a[i]),sum+a[i],i);
    }
}
signed main(){
ios::sync_with_stdio(0);
cin.tie(0);
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
for(int i=1;i<=n-2;i++){
    dfs(1,a[i],a[i],i);
}
cout<<cnt;
return 0;
}
