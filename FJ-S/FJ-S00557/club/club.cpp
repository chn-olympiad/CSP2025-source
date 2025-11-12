#include<bits/stdc++.h>
using namespace std;
int n,a[100005][5],ans;
void dfs(int k,int x,int y,int z,int sum){
if(x>n/2||y>n/2||z>n/2)return;
if(k>n){
ans=max(ans,sum);
return;
}
dfs(k+1,x+1,y,z,sum+a[k][1]);
dfs(k+1,x,y+1,z,sum+a[k][2]);
dfs(k+1,x,y,z+1,sum+a[k][3]);
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
while(t--){
cin>>n;
for(int i=1;i<=n;i++){
cin>>a[i][1]>>a[i][2]>>a[i][3];
}
ans=0;
dfs(1,0,0,0,0);
cout<<ans<<"\n";
}
return 0;
}
