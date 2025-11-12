#include<iostream>
#include<cstdio>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int c[15],a[15][1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>u[i]>>v[i]>>w[i];
        ans+=w[i];
    }
    for(int j=1;j<=k;j++){
        cin>>c[j];
        if(c[j]!=0){
            flag=false;
        }
        for(int i=1;i<=n;i++){
            cin>>a[j][i];
            if(a[j][i]!=0){
                flag=false;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}


