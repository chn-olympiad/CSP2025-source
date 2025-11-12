#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
int w;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    w=n*m;
    int u;
    for(int i=1;i<=w;i++){
        scanf("%d",&a[i]);
        if(i==1){
            u=a[i];
        }
    }
    int num=0;
    sort(a+1,a+1+w);
    for(int i=w;i>=1;i--){
        if(a[i]!=u){
            num++;
        }else{
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            for(int j=1;j<=m;j++){
                if(num==0){
                    printf("%d %d",i,j);
                    return 0;
                }
                num--;
            }

        }else{
            for(int j=m;j>=1;j--){
                if(num==0){
                    printf("%d %d",i,j);
                    return 0;
                }
                num--;
            }
        }


    }
    return 0;
}
