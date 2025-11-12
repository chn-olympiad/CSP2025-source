#include<bits/stdc++.h>
using namespace std;
struct node{
    int u,v,w;

}a[1000005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    int val,sum=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i].u>>a[i].v>>a[i].w;
        sum+=a[i].w;
    }
    cout<<sum;
    return 0;
}
