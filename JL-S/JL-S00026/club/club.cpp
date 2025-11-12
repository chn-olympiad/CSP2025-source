#include<bits/stdc++.h>
using namespace std;
bool vis[5005];
struct _{
int a1,a2,a3;
}a[100005];
int t;
unsigned long ans;
void dfs(int s,unsigned long cnt,int s1,int s2,int s3){
if(s==-1){
    ans=max(ans,cnt);
    return;
}


if(s1>0)dfs(s-1,cnt+a[s].a1,s1-!!a[s].a1,s2,s3);
if(s2>0)dfs(s-1,cnt+a[s].a2,s1,s2-!!a[s].a2,s3);

if(s3>0)dfs(s-1,cnt+a[s].a3,s1,s2-!!a[s].a3,s3-1);
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
scanf("%d",&t);
while(t--){
int n;
scanf("%d",&n);
for(int i=0;i<n;i++)scanf("%d%d%d",&a[i].a1,&a[i].a2,&a[i].a3);

dfs(n-1,0,n/2,n/2,n/2);
printf("%lld\n",ans);
ans=0;
}
    return 0;
}

