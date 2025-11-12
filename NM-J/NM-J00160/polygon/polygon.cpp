#include<bits/stdc++.h>
using namespace std;
int n;
int a[50008];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<3){
        printf("%d",0);
    }else{
        if(a[1]<a[2]+a[3]&&a[2]<a[1]+a[3]&&a[3]<a[1]+a[2]){
            printf("%d",1);
        }else{
            printf("%d",0);

        }
    }
    return 0;
}
