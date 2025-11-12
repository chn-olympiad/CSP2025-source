#include<bits/stdc++.h>
using namespace std;
int n,m,a,tmp,cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a);
    for(int i=1;i<n*m;i++){
        scanf("%d",&tmp);
        if(tmp>a)cnt++;
    }
    cnt++;
    int c=(cnt-1)/n;
    int r=cnt%n;
    printf("%d ",c+1);
    if(c%2==0){
        if(r==0)printf("%d",n);
        else printf("%d",r);
    }else{
        if(r==0)printf("1");
        else printf("%d",n-r+1);
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
