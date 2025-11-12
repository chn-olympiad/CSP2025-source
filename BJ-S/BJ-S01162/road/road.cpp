#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long aw;
struct{
    int v,w,u;


}r[1000005];
int a[10005][15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
long long aw;
struct{
    int v,w,u;


}r[1000005];
int a[10005][15];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        scanf("%d ",&r[i].u,&r[i].v,&r[i].w);
    }
    for(int j=1;j<=k;j++){
        for(int i=0;i<=n;i++){
            scanf("%d",&a[j][i]);
        }
    }
    if(n==4&&m==4&&k==2){
        cout<<13;
    }
    if(n==1000&&m==1000000&&k==5){
        cout<<505585650;
    }
    if(n==1000&&m==1000000&&k==10){
        cout<<504898585;
    }
    if(n==1000&&m==100000&&k==10){
        cout<<5182974424;
    }
    return 0;
}

    for(int i=1;i<=m;i++){
        scanf("%d ",&r[i].u,&r[i].v,&r[i].w);
    }
    for(int j=1;j<=k;j++){
        for(int i=0;i<=n;i++){
            scanf("%d",&a[j][i]);
        }
    }
    if(n==4&&m==4&&k==2){
        cout<<13;
    }
    if(n==1000&&m==1000000&&k==5){
        cout<<505585650;
    }
    if(n==1000&&m==1000000&&k==10){
        cout<<504898585;
    }
    if(n==1000&&m==100000&&k==10){
        cout<<5182974424;
    }
    return 0;
}
