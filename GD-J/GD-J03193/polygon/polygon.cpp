#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n<=3){
        int i,a[3];
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(n<3){
            printf("0");
        }else{
            int x=min(min(a[0],a[1]),a[2]),z=max(max(a[0],a[1]),a[2]),y=a[0]!=x&&a[0]!=z?a[0]:(a[1]!=x&&a[1]!=z?a[1]:a[2]);
            printf("%d",int(x+y>z));
        }
    }else{
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
