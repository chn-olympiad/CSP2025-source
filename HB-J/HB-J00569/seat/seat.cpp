#include<bits/stdc++.h>
using namespace std;
int n,m,pts[1001],r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;++i)scanf("%d",&pts[i]);
    r=pts[1];
    sort(pts+1,pts+n*m+1,cmp);
    int rs;
    for(int i=1;i<=m;++i){
        if(i%2==0){
            for(int k=n,j=1;k>=1;--k,++j){
                if(pts[n*i-n+j]==r){
                    printf("%d %d",i,k);
                    return 0;
                }
            }
        }else{
            for(int j=1;j<=n;++j){
                if(pts[n*i-n+j]==r){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
