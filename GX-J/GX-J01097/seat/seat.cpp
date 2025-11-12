#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,t;
struct ll{
    int x;
    bool b;
}a[210];
inline bool lu(ll xw,ll yw){
    return xw.x>yw.x;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    //nice
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i].x);
        a[i].b=false;
    }
    a[1].b=true;
    sort(a+1,a+n*m+1,lu);
    x=1,y=1,z=1,t=1;
    while(true){
        if(a[t].b==true){
            printf("%d %d\n",y,x);
            return 0;
        }
        t++;
        if(1==n){
            y++;
            continue;
        }
        if(x==n&&z==1){
            z=-1,y++;
        }else if(x==1&&z==(-1)){
            z=1,y++;
        }else{
            x+=z;
        }
        //printf("%d %d\n",x,y);
    }
    return 0;
}
