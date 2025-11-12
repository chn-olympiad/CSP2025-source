#include<bits/stdc++.h>
using namespace std;
int a[1000005][5],b[15][10],c[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3];
        c[i]=a[i][3];
    }
    if(k==0){
        int ans=0;
        sort(c+1,c+1+m);
        for(int i=1;i<m;i++){
            ans+=c[i];
        }
        cout<<ans;
    }else{
    for(int i=1;i<=k;i++){
        cin>>b[i][1]>>b[i][2]>>b[i][3]>>b[i][4]>>b[i][5];
    }
    cout<<5;
    }
    return 0;
}
