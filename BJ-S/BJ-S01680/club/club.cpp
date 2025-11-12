#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,a[N][5],b[5],maxn;
void dfs(int step){
    if(step>n){
        maxn=max(maxn,ans);
        return;
    }for(int i=1;i<=3;i++){
        if(b[i]>=n/2)continue;
        b[i]++;
        ans+=a[step][i];
        dfs(step+1);
        b[i]--;
        ans-=a[step][i];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        maxn=0,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
        }dfs(1);
        cout<<maxn<<'\n';
    }
    return 0;
}

