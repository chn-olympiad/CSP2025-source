#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001],t=0,x=1,y=1,g;
char c='+';
bool cmp(const int &A,const int &B){
    return A>B;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    g=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    while(y!=m||x!=n){
        t++;
        if(a[t]==g){
            break;
        }
        if(c=='-'){
            x--;
        }
        if(c=='+'){
            x++;
        }
        if(x==n){
            t++;
            if(a[t]==g){
                break;
            }
            y++;
            c='-';
        }
        if(x==1){
            t++;
            if(a[t]==g){
                break;
            }
            y++;
            c='+';
        }
    }
    printf("%d %d",y,x);
    return 0;
}
