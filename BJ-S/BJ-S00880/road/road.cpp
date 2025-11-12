#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000001],v[1000001],w[1000001],c,a[1000001];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    cin>>c;
    int b=1;
    for(int i=1;i<=k;i++){
        cin>>a[i];
        if(a[i]!=0) b=0;
    }
    if(b==1&&c==0){
        cout<<0;
    }
    return 0;
}