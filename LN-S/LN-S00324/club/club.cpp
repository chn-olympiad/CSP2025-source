#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    int t,d[3]={1,2,3};
    scanf("%d",&t);
    int n[t],i=0,j=0,a[i][j];

    for(int x=0;x<=t;x++){
        scanf("%d",&n[x]);
        for(;i<=n[x];i++){
            for(;j<=2;j++){
                scanf("%d",&a[i][j]);
            }
        }
    }
    int num[t];
    for(int x=0;x<=t;x++){
        for(;i<=n[x];i++){
            for(;j<=2;j++){
                if(a[i][j]>a[i][j+1]>a[i][j+2]){
                    num[x]+=a[i][j];
                }else if(a[i][j]<a[i][j+1]>a[i][j+2]){
                    num[x]+=a[i][j+1];
                }else if(a[i][j]<a[i][j+1]<a[i][j+2]){
                    num[x]+=a[i][j+2];
                }
            }
        }
        printf("%d ",num[x]);
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
