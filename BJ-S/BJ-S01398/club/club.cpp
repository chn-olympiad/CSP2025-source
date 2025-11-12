#include <bits/stdc++.h>
using namespace std;
int n,tn=n,ans;
int a[3][210],f[210],g[3]={n/2,n/2,n/2};
bool cmp(int x,int y){
    return x>y;
}
void dfs(int x){
    if(g[0]<0||g[1]<0||g[2]<0) return;
    if(tn==0){
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=a[f[i]][i];
        }
        ans=max(ans,cnt);
    }
    for(int i=0;i<=2;i++){
        g[i]--;
        tn--;
        f[x]=i;
        dfs(x+1);
        f[x]=i;
        tn++;
        g[i]++;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        memset(g,0,sizeof(g));
        cin>>n;
        tn=n;
        g[0]=n/2;
        g[1]=n/2;
        g[2]=n/2;
        bool f=0;
        for(int i=0;i<n;i++){
            cin>>a[0][i]>>a[1][i]>>a[2][i];
            f&=a[i][1]&a[i][2];
        }
        if(f==0){
            sort(a[0]+1,a[0]+n+1,cmp);
            int sum=0;
            for(int i=1;i<=n/2;i++) sum+=a[0][i];
            cout<<sum<<endl;
            continue;
        }
        ans=0;
        dfs(0);
        cout<<ans<<endl;
    }
    return 0;
}
