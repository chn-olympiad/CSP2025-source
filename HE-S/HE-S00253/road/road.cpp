#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k,min,ans=0;
    int u[100005],v[100005],w[100005];
    int c[100005],a[100005];
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> u[i] >> v[i] >> w[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(m=1){
            w[i]+=1;
            ans++;
            }
            if(k=1){
           c[j]+=1;
           w[i]+=1;
           ans++;
        }
        ans=(min,ans);
        cout <<ans;
    }
}
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    return 0;
}
