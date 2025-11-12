#include<bits/stdc++.h>
using namespace std;
int n,m,c[150],xc,mc,xx,yy,zy;
int abc(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>c[i];
    }
    xc=c[1];
    sort(c+1,c+n*m+1,abc);
    for(int i=1;i<=n*m;i++){
        if(xc==c[i]){
            mc=i;
            break;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                zy++;
                if(zy==mc){
                    xx=i;
                    yy=j;
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                zy++;
                if(zy==mc){
                    xx=i;
                    yy=j;
                }
            }
        }
    }
    cout<<xx<<" "<<yy;
    return 0;
}
