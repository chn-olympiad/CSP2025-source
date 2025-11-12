#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
int n,k,arr[MAXN],nm[MAXN],st[MAXN],en[MAXN],ans;
int work(int l,int r){
    int cur=arr[l];
    for(int i=l+1;i<=r;i++) cur=cur^arr[i];
    return cur;
}
int solve(int num){
     int cur=0;
     for(int i=1;i<=num;i++){
        if(nm[i]==k) cur++;
     }
     return cur;
}
void dfs(int num,int s,int e){
    st[num]=s;
    en[num-1]=e;
    en[num]=n;
    nm[num-1]=work(st[num-1],en[num-1]);
    nm[num]=work(st[num],en[num]);
    ans=max(ans,solve(num));
    if(s>=n || num>=n) return;
    for(int i=s;i<=n;i++){
        dfs(num+1,i+1,i);
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
    if(k==0)
        for(int i=1;i<=n;i++)
            if(arr[i]==0) ans++;
    else dfs(1,1,0);
    printf("%d",ans);
    return 0;
}
