#include <bits/stdc++.h>

using namespace std;

int seat[200];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++) scanf("%d",&seat[i]);
    int R=seat[1];
    sort(seat+1,seat+n*m+1,cmp);
    int c=1,r=1;
    for(int i=1;i<=n*m;i++){
        if(seat[i]==R) break;
        if(c%2==1){
            if(r==n) c++;
            else r++;
        }else{
            if(r==1) c++;
            else r--;
        }
    }
    printf("%d %d",c,r);
    return 0;
}
