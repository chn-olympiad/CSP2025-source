#include<bits/stdc++.h>
using namespace std;

int w[1000500],u[1000500],v[1000500],c[1000500],z[1000500];
struct node{
    int l,r,v;
}a[1000500];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k,sum=0;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    for(int i=1;i<=k;i++){
        cin>>c[i];
        if(c[i]==0){
            sum++;
        }
        for(int j=1;j<=m+1;j++){
            cin>>z[j];
            if(z[j]==0){
                sum++;
            }
        }
    }
    if(sum==k+m*k){
        cout<<0;
        return 0;
    }
    if(k==0){
        for(int i=1;i<=m;i++){
            cin>>u[i]>>v[i]>>w[i];
            a[i].l=u[i];
            a[i].r=v[i];
            a[i].v=w[i];
        }
        if(m==n-1){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=w[i];
            }
            cout<<sum;
            return 0;
        }
        else{
            int sum=0,u=n-1;
            sort(w+1,w+1+n);
            for(int i=1;i<=u;i++){
                sum+=w[i];
            }
            cout<<sum;
            return 0;
        }
    }
    return 0;
}
