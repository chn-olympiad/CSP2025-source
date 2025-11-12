#include<bits/stdc++.h>
using namespace std;
int n,m,a,k,t=1,l,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d%d",&n,&m,&a);
    for(int i=2;i<=m*n;i++){
        scanf("%d",&k);
        if(k>a) t++;
    }
    l=(t+n-1)/n;
    if(l%2==1) r=t-(l-1)*n;
    else r=l*n-t+1;
    printf("%d %d\n",l,r);
    return 0;
}
