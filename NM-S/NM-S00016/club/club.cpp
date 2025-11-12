#include<bits/stdc++.h>
using namespace std;
const int N=1e5+3;
int t,n,a[N][5],ans,flag1,flag2;
int p[N];
void dfs(int cnt1,int cnt2,int cnt3,int m,int last,int sum){
    if(m==n&&cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2) {ans=max(ans,sum);return;}
    if(cnt1>n/2||cnt2>n/2||cnt3>n/2) return;
    dfs(cnt1+1,cnt2,cnt3,m+1,1,sum+a[m+1][1]);
    dfs(cnt1,cnt2+1,cnt3,m+1,2,sum+a[m+1][2]);
    dfs(cnt1,cnt2,cnt3+1,m+1,3,sum+a[m+1][3]);
}
int solve(){
    flag2=flag1=0;
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        if(a[i][1]>0) flag1=1;
        if(a[i][2]>0) flag2=1;
    }
    if(flag1==0&&flag2==0){
        for(int i=1;i<N;i++) p[i]=0;
        for(int i=1;i<=n;i++) p[i]=a[i][2];
        sort(p+1,p+n+1,greater<int>());
        for(int i=1;i<=n/2;i++) ans+=p[i];
        cout<<ans<<"\n";
        return 0;
    }else if(flag2==0){
        for(int i=1;i<=n;i++){
            ans+=max(a[i][1],a[i][2]);
        }
        cout<<ans<<"\n";
        return 0;
    }
    dfs(0,0,0,0,0,0);
    cout<<ans<<"\n";
    return 0;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    cin.tie(0);
    while (t--){
       solve();
    }
    return 0;
}