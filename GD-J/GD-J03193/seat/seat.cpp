#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int i,n,m,s,q,t,r,c,a[101];
    memset(a,0,sizeof(a));
    scanf("%d%d%d",&n,&m,&q);
    a[q]++;
    s=n*m;
    for(i=1;i<s;i++){
        scanf("%d",&t);
        a[t]++;
    }
    t=0;
    for(i=100;i>=q;i--){
        t+=a[i];
    }
    c=(t-1)/n+1;
    if(c&1){
        r=t-(c-1)*n;
    }else{
        r=c*n-t+1;
    }
    printf("%d %d",c,r);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
