#include<bits/stdc++.h>
using namespace std;
int zz[40][40],sz[1600];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,mid,zj;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sz[i];
        if(i==1){
            mid=sz[i];
        }
    }sort(sz+1,sz+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(sz[i]==mid){
            zj=i;
            break;
        }
    }/*cout<<zj<<" ";
    for(int i=1;i<=n*m;i++){
        cout<<sz[i]<<" ";
    }cout<<endl;*/
    if(zj%n!=0){
        cout<<(zj/n)+1<<" ";
    }else{
        cout<<(zj/n)<<" ";
    }if((zj/n)%2==0){
        if(zj%n==0){
            cout<<1;
            return 0;
        }cout<<zj%n;
    }else{
        if(zj%n==0){
            cout<<n;
            return 0;
        }cout<<n-(zj%n)+1;
    }return 0;
}