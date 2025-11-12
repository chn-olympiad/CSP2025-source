#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int x=1,y=1;
    for(int i=2;i<=n*m;i++){
        if(a[1]<a[i]){
            if(x%2==1){
                if(y==m){
                    x++;
                }else{
                    y++;
                }
            }else if(x%2==0){
                if(y==1){
                    x++;
                }else{
                    y--;
                }
            }

        }
    }
    printf("%d %d",x,y);
    return 0;
}
