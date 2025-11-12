#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],f,x=1,y=1,op;
bool cmp(const int &x,const int &y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
    f=a[1];
    sort(a+1,a+n*m+1,cmp);
    if(a[1]==f){
        printf("%d %d",x,y);
        return 0;
    }
    for(int i=2;i<=n*m;i++){
        if(op==0){
            y++;
            if(y>n){
                y=n;
                x++;
                op=1;
            }
        }
        else{
            y--;
            if(y<1){
                y=1;
                x++;
                op=0;
            }
        }
        if(a[i]==f){
            printf("%d %d",x,y);
            break;
        }
    }
    return 0;
}
