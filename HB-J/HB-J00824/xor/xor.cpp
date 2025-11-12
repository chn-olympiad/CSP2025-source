#include<bits/stdc++.h>
#define pii pair<long long,long long>
using namespace std;
long long n,k,a[500005],now_index=1,ans=-1;
pii num[500005];
bool vis[500005];
bool flag1=1;
void solve1(){
    if(k==0)cout<<n/2;
    if(k==1)cout<<n;
}
void dfs(long long now,long long cnt){
    if(now==now_index){
        ans=max(ans,cnt);
        return;
    }
    bool flag=1;
    int l=num[now].first,r=num[now].second;
    for(int i=l;i<=r;i++){
        if(vis[i]){
            flag=0;
            break;
        }
        else vis[i]=1;
    }
    if(flag){
        dfs(now+1,cnt+1);
        for(int i=l;i<=r;i++)vis[i]=0;
    }
    dfs(now+1,cnt);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=1;j<=i;j++){
            int sum=a[j];
            for(int l=j+1;l<=i;l++)sum^=a[l];
            if(sum==k){
                num[now_index]=(pii){j,i};
                now_index++;
            }
        }
        if(a[i]!=1)flag1=0;
    }
    if(flag1)solve1();
    else{
        dfs(1,0);
        cout<<ans;
    }
    return 0;
}
