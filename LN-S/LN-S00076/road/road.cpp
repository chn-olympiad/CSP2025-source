#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,k;
int t[N][N];
int ans;
bool flag=1;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        t[u][v]=w;
    }
    if(k==0){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans+=t[i][j];
            }
        }
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=k;i++){
        int c;
        int a[N];
        cin>>c;
        if(c!=0){
            flag=0;
        }
        for(int j=1;j<=n;i++){
            cin>>a[i];
            if(a[i]!=0){
                flag=0;
            }
        }
        if(flag==1){
            cout<<0;
            return 0;
        }
        int ans1=0;
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                ans1+=t[j][k];
            }
        }
        for(int j=1;j<=n;j++){
                c+=a[j];
        }
        ans=min(ans1,c);
    }
    cout<<ans;
    return 0;
}
