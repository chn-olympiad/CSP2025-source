#include <bits/stdc++.h>
using namespace std;
long long a[100005],n,k,i,j,l[100005],r[100005];
int maxn=-1;
int fxor(int x,int y){
    int a[25]={0},b[25]={0},c[25]={0};
    int maxi=1,t=0;
    for(i=1;i<=24;i++) maxi*=2;
    for(i=maxi;i>0;i/=2){
        if(x-i>=0){
            a[t]=1;
            x-=i;
        }
        t++;
    }
    t=0;
    for(i=maxi;i>0;i/=2){
        if(y-i>=0){
            a[t]=1;
            y-=i;
        }
        t++;
    }
    for(i=0;i<25;i++){
        if((a[i]||b[i])&&!(a[i]&&b[i])) c[i]=1;
    }
    long long num=0;
    t=1;
    for(i=24;i>=0;i--){
        num+=(int)c[i]*t;
        t*=2;
    }
    return num;
}
int xorn(int x,int y){
    int sx=a[x];
    for(x=x+1;x<=y;x++){
        sx=fxor(sx,a[x]);
        if(sx==k) return 1+(x+1,y);
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    for(i=0;i<n;i++){
        sum=max(xorn(i,n-1),maxn);
    }
    cout<<sum;
    return 0;
}
