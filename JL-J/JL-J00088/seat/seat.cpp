#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,arr[150];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m*n;i++) scanf("%d",&arr[i]);
    int ans=arr[1];
    sort(arr+1,arr+n*m+1,cmp);
    int value=1;
    for(int i=1;i<=m;i++){
        if(i%2==1) {
            for(int j=1;j<=n;j++) {
                if(arr[value]==ans)
                    printf("%d %d",i,j);
                value++;
            }
        }
        else if(i%2==0){
            for(int j=n;j>=1;j--) {
                if(arr[value]==ans)
                    printf("%d %d",i,j);
                value++;
            }
        }
        
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}