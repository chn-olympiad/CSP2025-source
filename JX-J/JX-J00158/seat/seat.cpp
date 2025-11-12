#include<bits/stdc++.h>
using namespace std;
int n,m,a,cnt=1,x,ans;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a);
        if(i==1){
            x=a;
        }
        else{
            if(a>x) cnt++;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                ans++;
                if(ans==cnt){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                ans++;
                if(ans==cnt){
                    printf("%d %d",i,j);
                    return 0;
                }
            }
        }
    }
}
