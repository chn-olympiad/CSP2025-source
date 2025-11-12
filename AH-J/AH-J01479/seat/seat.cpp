#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 1005;
int a[N];
bool cmp(int x,int y){
    return x > y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%d",&a[i]);
    }
    int ans = a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int x = 1;
    int y = 1;
    int in = 1;
    int p = 0;
    int fx = 0;//0往下 1往上
    while(1){
        //cout<<x<<" "<<y<<endl;
        //cout<<ans<<" "<<a[in]<<endl;
        if(ans == a[in]){
            printf("%d %d",x,y);
            break;
        }
        if(fx == 0){
            if(y+1 <= n){
                y++;
            }else{
                fx = 1;
                x++;
            }
        }else{
            if(y-1 > 0){
                y--;
            }else{
                fx = 0;
                x++;
            }
        }
        in++;
    }
    return 0;
}
