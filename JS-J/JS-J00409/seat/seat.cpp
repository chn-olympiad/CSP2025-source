#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int b[11][11];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int k=a[1];
    sort(a+1,a+n*m+1);
    int p=0;
    for(int i=n;i>=1;i--){
        if(i%2==1){
            for(int j=m;j>=1;j--){
                p++;
                b[j][i]=a[p];
                if(a[p]==k){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
        else{
            for(int j=1;j<=m;j++){
                p++;
                b[j][i]=a[p];
                if(a[p]==k){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
    }
    return 0;
}
