#include <bits/stdc++.h>
using namespace std;

int a[1010];
bool cmp(int A,int B){
    return A>B;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    int s=0;
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    s=a[1];
    sort(a+1,a+n*m+1,cmp);
    int dir=1;
    int x=1,y=1,tot=1;
    while (1){
        if (a[tot]==s){
            printf("%d %d",x,y);
            return 0;
        }
        if (y+dir<1 || y+dir>n){
            dir=-dir;
            x++;
        }
        else{
            y+=dir;
        }
        tot++;
    }
    return 0;
}

