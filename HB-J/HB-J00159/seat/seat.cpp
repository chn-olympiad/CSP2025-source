#include <bits/stdc++.h>
using namespace std;
int a[20][20],b[120],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    int x=m*n;
    for(int i=1;i<=x;i++){
        scanf("%d",&b[i]);
    }
    int R=b[1];
    sort(b+1,b+x+1);
    int j;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            j=1;
        }else{
            j=n;
        }
        for(;;){
            if(i%2==1){
                if(j>n)
                    break;
            }else{
                if(j<1)
                    break;
            }
            a[j][i]=b[x];
            x--;
            if(i%2==1){
                j++;
            }else{
                j--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==R){
                cout<<j<<' '<<i;
            }
            }
        }
    return 0;
}

