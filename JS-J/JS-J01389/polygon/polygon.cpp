#include <bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans;
void dfs(int idx,int sum,int cnt){
    if(idx>n) return;
    if(cnt>=3&&sum>2*a[idx]){
      ans++;
    }
    dfs(idx+1,sum+a[idx+1],cnt+1);
    dfs(idx+1,sum,cnt);
}
int main(){
   freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   sort(a+1,a+n+1);
   if(n<=2) cout<<0<<endl;
   dfs(0,0,0);
   cout<<ans<<endl;
   return 0;
}
