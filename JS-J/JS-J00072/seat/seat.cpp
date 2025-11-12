#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],R,Rp;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    R=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            Rp=i;
            break;
        }
    }
    int l=(Rp-1)/n+1;
    if(l%2==1){
        int h=(Rp-(l-1)*n);
        printf("%d %d",l,h);
    }else{
        int h=(n-(Rp-(l-1)*n)+1);
        printf("%d %d",l,h);
    }
    cout<<"\n";
    return 0;
}
