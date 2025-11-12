#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],siz,c[110][110],x;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    siz=n*m;
    for(int i=1;i<=siz;i++){
        scanf("%d",&a[i]);
    }
    x=a[1];
    sort(a+1,a+siz+1);
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                c[j][i]=a[siz--];
            }
        }else{
            for(int j=n;j>=1;j--){
                c[j][i]=a[siz--];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(c[i][j]==x){
                printf("%d %d",j,i);
                return 0;
            }
        }
    }
}
