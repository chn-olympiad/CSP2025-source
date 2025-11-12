#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=15;
int a[N][N];
int c[N*N];
bool cmp(int xx,int yy){
    return xx>yy;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int r=n*m;
    for(int i=1;i<=r;++i){
        scanf("%d",&c[i]);
    }
    int q=c[1];
    int x;
    sort(c+1,c+r+1,cmp);
    for(int i=1;i<=r;++i){
        if(c[i]==q){
            x=i;
        }
    }
    int h,l,dy;
    if(x%n==0){
       l=x/n;
    }else{
        l=x/n+1;
    }
    if(x%n==0){
        dy=n;
    }else{
        dy=x%n;
    }
    int ys=l%2;
    if(ys==1){
        h=dy;
    }else{
        h=n-dy+1;
    }
    printf("%d %d\n",l,h);
    return 0;
}
