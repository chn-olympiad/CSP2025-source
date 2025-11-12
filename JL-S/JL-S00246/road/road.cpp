#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int c1,x,y,n,m,k,u[100924],v[100924],w[100924],c[100924],ans=0,l[100924],anq,o=1,aj[100924];
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
        cin>>u[i]>>v[i]>>w[i];
    for(int i=1;i<=m;i++)
        l[i]=w[i];
    sort(l+1,l+m);
    for(int i=1;i<=n-1;i++)
        ans+=l[i];

    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]<c1)c1=c[i];
        for(int j=1;j<=n;j++)
            cin>>aj[j];
        }
    sort(aj+1,aj+n);

    for(int i=1;i<=k;i++){
    for(int i=1;i<=m;i++)
    if(l[n-o]==w[i]){
        x=u[i];
        y=v[i];
    }
    while(-1<0){
        anq=ans-l[n-o];
        anq+=c1;
        anq+=aj[2]+aj[1];
        if(anq<ans){
            ans=anq;
            o++;
        }
    else break;
    }
    }
    cout<<ans;

}
