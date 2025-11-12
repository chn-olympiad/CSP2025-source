#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cctype>
using namespace std;
int n,m,k,u[100005],v[100005],w[100005],c[100005],a[100005],ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k+1;i++){
        cin>>c[i]>>a[i];
    }
    for(int i=1;i<=m;i++){
        ans+=w[i];
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
