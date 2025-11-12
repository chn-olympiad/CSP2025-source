#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10004][4];
int b[16][1000006];
int c[1000004];
int mc;
int ew=1e9;
int ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        c[i]=1000000005;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        c[a[i][2]]=min(c[a[i][2]],a[i][3]);
        c[a[i][1]]=min(c[a[i][1]],a[i][3]);
    }
    for(int i=1;i<=k;i++){
        cin>>b[i][1];
        ew=min(ew,b[i][1]);
        if(ew==b[i][1]){
            mc=i;
        }
        for(int j=2;j<=m+1;j++){
            cin>>b[i][j];
        }
    }
    if(ew==1e9)ew=0;
    for(int i=1;i<=n;i++){
        c[i]=min(c[i],b[mc][i+1]);
        ans+=c[i];
    }
    ans+=ew;
    cout<<ans;
    return 0;
}
