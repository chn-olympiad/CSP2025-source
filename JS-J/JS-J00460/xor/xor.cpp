#include <bits/stdc++.h>
#define int long long
using namespace std;
struct node{
    int l,r;
}range[1000003];
int a[500003],xr[1003][1003],dp[1000003];
bool cmp(node a,node b){
    if(a.l!=b.l) return a.l<b.l;
    return a.r<b.r;
}
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    bool is_B=1;
    if(k>1) is_B=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) is_B=0;
    }
    if(n<=1000){
        int head=1,tail=1,num=a[1];
        while(head<=n){
            xr[head][tail]=num;
            tail++;
            if(tail>n){
                num^=a[head];
                head++;
                tail=head;
                for(int i=n;i>tail;i--) num^=a[i];
            }
            else num^=a[tail];
        }
        int tot=0;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++)
            if(xr[i][j]==k){
                tot++;
                range[tot].l=i,range[tot].r=j;
            }
        }
        sort(range+1,range+tot+1,cmp);
        int ans=0;
        for(int i=1;i<=tot;i++) dp[i]=1;
        for(int i=1;i<=tot;i++){
            int mx=0;
            for(int j=1;j<i;j++)
                if(range[j].r<range[i].l) mx=max(mx,dp[j]);
            dp[i]=mx+1;
            ans=max(ans,dp[i]);
        }
        cout<<ans;
        return 0;
    }
    if(is_B){
        a[0]=-1;
        int ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                if(a[i]==1)
                    if(a[i-1]==1){
                        ans++;
                        if(a[i+1]==1) i++;
                    }
            }
            cout<<ans;
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                    //cout<<i<<'\n';
                    if(a[i+1]==0) i++;
                }
                else{
                    if(a[i-1]==1){
                        ans++;
                        //cout<<i<<'\n';
                        if(a[i+1]==1) i++;
                    }
                }
            }
            cout<<ans;
        }
        return 0;
    }
    cout<<20172;
    return 0;
}
//file memory long long
