#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d%d",&n,&m,&a[1]);
    int tmp=a[1];
    for(int i=2;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n*m+1,cmp);
    int ttmp=1;
    for(;ttmp<=n*m;ttmp++){
        if(a[ttmp]==tmp){
            break;
        }
    }
    int tmmp=(ttmp-1)/n+1;
    int tmpp=ttmp%n;
    if(tmpp==0){
        tmpp=n;
    }
    if(tmmp%2==0){
        printf("%d %d",tmmp,n+1-tmpp);
    }
    else{
        printf("%d %d",tmmp,tmpp);
    }
}
