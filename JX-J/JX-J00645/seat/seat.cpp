#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000],x;
bool cmp(int p,int q){
    return p>q;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    x=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[(i-1)*n+j]==x){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }else{
            int p=0;
            for(int j=n;j>=1;j--){
                p++;
                if(a[(i-1)*n+p]==x){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
