#include<bits/stdc++.h>
using namespace std;
int k,n,a[10010],b[10010][2],cnt,ans1,ans;
void dfs(int x){
    ans=max(ans1,ans);
    for(int i=1;i<=n;i++){
        if(b[i][0]>x){
            ans1++;
          dfs(b[i][1]);
            ans1--;
        }
    }
}
int main(){
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);
   cin>>n>>k;
   for(int i=1;i<=n;i++)cin>>a[i];
   for(int i=1;i<=n;i++){
       int am=0;
       for(int j=i;j<=n;j++){
        am^=a[j];
        if(am==k){
            b[++cnt][0]=i,b[cnt][1]=j;
            break;
        }
       }
   }
   dfs(0);
   cout<<ans;
   return 0;
}
