#include<bits/stdc++.h>
using namespace std;
//mark greatest ZhuYunFan;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    int n,m,a[102],r=0;
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
        if(i==1)r=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int k=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(a[k++]==r){printf("%d %d",i,j);return 0;}
            }
        }else if(i%2==0){
            for(int j=n;j>=1;j--){
                if(a[k++]==r){printf("%d %d",i,j);return 0;}
            }
        }

    }
    return 0;
}
