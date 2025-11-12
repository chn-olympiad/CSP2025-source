#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int n;
int a[100005][4],f[201][101][101],p[100005];
void solve(){
    memset(f,0,sizeof f);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++){
            cin>>a[i][j];
        }
    }
    if(n>200){
        int ans=0;
        int c[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            if(a[i][1]<a[i][2]){
                ans+=a[i][2];
                c[2]++;
            }
            if(a[i][1]>a[i][2]){
                ans+=a[i][1];
                c[1]++;
            }
        }
        if(c[1]>n/2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i][1]>a[i][2]){
                    p[++cnt]=a[i][1]-a[i][2];
                }
            }
            sort(p+1,p+cnt+1);
            for(int i=1;i<=c[1]-n/2;i++){
                ans-=p[i];
            }
            cout<<ans<<"\n";
            return;
        }
        if(c[2]>n/2){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i][2]>a[i][1]){
                    p[++cnt]=a[i][2]-a[i][1];
                }
            }
            sort(p+1,p+cnt+1);
            for(int i=1;i<=c[2]-n/2;i++){
                ans-=p[i];
            }
            cout<<ans<<"\n";
            return;
        }
    }
    f[1][1][0]=a[1][1];
    f[1][0][1]=a[1][2];
    f[1][0][0]=a[1][3];
    for(int i=2;i<=n;i++){
        for(int x=0;x<=n/2&&x<=i;x++){
            for(int y=0;y<=n/2&&x+y<=i;y++){
                int z=i-x-y;
                if(z>n/2){
                    continue;
                }
                if(x>0)
                    f[i][x][y]=max(f[i-1][x-1][y]+a[i][1],f[i][x][y]);
                if(y>0)
                    f[i][x][y]=max(f[i-1][x][y-1]+a[i][2],f[i][x][y]);
                if(z>0)
                    f[i][x][y]=max(f[i-1][x][y]+a[i][3],f[i][x][y]);
            }
        }
    }
    int ans=0;
    for(int x=0;x<=n/2;x++){
        for(int y=0;y<=n/2&&x+y<=n;y++){
            int z=n-x-y;
            if(z>n/2){
                continue;
            }
            ans=max(ans,f[n][x][y]);
        }
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
