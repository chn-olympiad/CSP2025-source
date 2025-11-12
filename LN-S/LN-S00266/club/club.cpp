#include<bits/stdc++.h>
using namespace std;
long long t,n,a[114514][4],d[114514],ans,maxa,temp;

void dfs(long long cnt,long long cnt1,long long cnt2,long long cnt3,long long value){
    //temp++;
    if(value+(n-cnt)*maxa<=ans) return;
    if(cnt==n){
        ans=max(value,ans);
        //cout<<"test "<<cnt1<<" "<<cnt2<<" "<<cnt3<<" "<<value<<"  runtime"<<temp<<endl;
        return;
    }
    for(int i=1;i<=cnt+1;i++){
        if(d[i]) continue;
        d[i]=1;
        if(cnt1<n/2){
            dfs(cnt+1,cnt1+1,cnt2,cnt3,value+a[i][1]);
        }
        if(cnt2<n/2){
            dfs(cnt+1,cnt1,cnt2+1,cnt3,value+a[i][2]);
        }
        if(cnt3<n/2){
            dfs(cnt+1,cnt1,cnt2,cnt3+1,value+a[i][3]);
        }
        d[i]=0;
    }
    return;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                scanf("%lld",&a[i][j]);
                maxa=max(a[i][j],maxa);
            }
        }
        ans=0;
        dfs(0,0,0,0,0);
        cout<<ans<<endl;
    }
    return 0;
}
