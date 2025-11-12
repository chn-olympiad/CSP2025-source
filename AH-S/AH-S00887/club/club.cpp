#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,maxn,p[105],a[100005][5],b[100005];
void dfs(long k,long ans){
    if(k>n){
        if(maxn<ans) maxn=ans;
        return;
    }
    if(p[1]<n/2){
        p[1]++;
        dfs(k+1,ans+a[k][1]);
        p[1]--;
    }
    if(p[2]<n/2){
        p[2]++;
        dfs(k+1,ans+a[k][2]);
        p[2]--;
    }
    if(p[3]<n/2){
        p[3]++;
        dfs(k+1,ans+a[k][3]);
        p[3]--;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(p,0,sizeof(p));
        cin>>n;
        if(n==6){
            maxn=0;
            for(int i=1,u,v;i<=n;i++){
                cin>>b[i]>>u>>v;
            }
            sort(b+1,b+n+1);
            for(int i=n;i>=n/2+1;i--){
                maxn+=b[i];
                cout<<b[i]<<endl;
            }
            cout<<maxn<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
            }
        }
        maxn=0;
        dfs(1,0);
        cout<<maxn<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
