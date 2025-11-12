#include<bits/stdc++.h>
#define N 1003
using namespace std;
int n,m;
int x;
int rk;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d",&x);
    rk=1;
    for(int i=2;i<=n*m;i++){
        int a;
        scanf("%d",&a);
        if(a>x)rk++;
    }
    int a,b;
    a=1;
    b=1;
    rk--;
    while(rk>=2*n){
        b+=2;
        rk-=2*n;
    }
    for(int i=2;i<=n;i++){
        if(rk){
            rk--;
            a++;
        }
    }
    if(rk){
        rk--;
        b++;
        for(int i=2;i<=n;i++){
            if(rk){
                rk--;
                a--;
            }
        }
    }
    printf("%d %d\n",b,a);
}