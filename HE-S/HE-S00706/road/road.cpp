#include<bits/stdc++.h>
using namespace std;
int a[10005],sum;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        if(a[x]==0 || a[y]==0){
            a[x]=a[y]=z;
            sum+=z;
        }
        else{
            if(z<a[z] || z<a[y]){
                sum-=max(a[x],a[y]);
                sum+=z;
                a[x]=a[y]=z;
            }
        }
    }
    cout<<sum;
    return 0;
}
