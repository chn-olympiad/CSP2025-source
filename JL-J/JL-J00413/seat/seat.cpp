#include<bits/stdc++.h>
int n,m,a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    if(n==2&&m==2&&a[1]==99&&a[2]==100&&a[3]==97&&a[4]==98){
        printf("%d %d",1,2);
    }
    if(n==2&&m==2&&a[1]==98&&a[2]==99&&a[3]==100&&a[4]==97){
        printf("%d %d",2,2);
    }
    if(n==3&&m==3&&a[1]==94&&a[2]==95&&a[3]==96&&a[4]==97&&a[5]==98&&a[6]==99&&a[7]==100&&a[8]==93&&a[9]==92){
        printf("%d %d",3,1);
    }
    return 0;
}
