#include <bits/stdc++.h>
using namespace std;
int n,m,a[15][15];
int b[105],k;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&b[i]);
    }
    int k=b[1];
    stable_sort(b+1,b+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(i%2){
            for(int j=1;j<=n;j++){
                a[i][j]=b[++cnt];
                if(a[i][j]==k){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
        else{
             for(int j=n;j>=1;j--){
                a[i][j]=b[++cnt];
                if(a[i][j]==k){
                    printf("%d %d",i,j);
                    return 0;
                }
             }
        }
    }
    return 0;
}
