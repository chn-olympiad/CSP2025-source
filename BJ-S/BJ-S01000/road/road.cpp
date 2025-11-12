#include<bits/stdc++.h>
using namespace std;
int a[2001],b,c,d[2001],ans=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,m,k,u,v,w,pre=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        pre+=w;
    }
    cout<<pre;
    return 0;
}
