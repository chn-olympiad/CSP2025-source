#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[111];
int k=1;
pair<int,int> to_snack_zb(int x){
    int r=0,c=0;
    c=ceil(x*1.0/n);
    if(c%2==1){
        r=x%n;
        if(r==0) r=n;
    }else{
        r=n+1-x%n;
        if(r==n+1) r=1;
    }
    return make_pair(c,r);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(i!=1&&a[i]>a[1]) k++;
    }
    pair<int,int> zb=to_snack_zb(k);
    printf("%d %d",zb.first,zb.second);
    return 0;
}
