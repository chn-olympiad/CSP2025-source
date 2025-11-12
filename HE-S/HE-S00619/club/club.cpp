#include<bits/stdc++.h>
using namespace std;
int n,t,a1[100005],a2[100005],a3[100005];
long long x,y,z,ans;
bool cmp(int a,int b){
return a>b;
}
int dfs(long long ans,int s1,int s2,int s3,int j){
if(s1>n/2) return ans-a1[j-1];
if(s2>n/2) return ans-a2[j-1];
if(s3>n/2) return ans-a3[j-1];
x=dfs(ans+a1[j],s1+1,s2,s3,j+1);
y=dfs(ans+a2[j],s1,s2+1,s3,j+1);
z=dfs(ans+a3[j],s1,s2,s3+1,j+1);
return max(max(x,y),z);
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
cin>>t;
for(int i=1;i<=t;i++){
cin>>n;
for(int i=1;i<=n;i++){
cin>>a1[i]>>a2[i]>>a3[i];
}
if(n>30){
sort(a1+1,a1+n+1,cmp);
for(int i=1;i<=n/2;i++){
ans+=a1[i];
}
}else{
x=dfs(a1[1],1,0,0,2);
y=dfs(a2[1],0,1,0,2);
z=dfs(a3[1],0,0,1,2);
ans=max(max(x,y),z);
}
cout<<ans<<endl;
}
fclose(stdin);
fclose(stdout);
return 0;
}
