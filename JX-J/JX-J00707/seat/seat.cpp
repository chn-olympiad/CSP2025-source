#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a,b,c,r,k=1;
void solve(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1&&j==1) scanf("%d",&a);
            else{
                scanf("%d",&b);
                if(b>a) k++;
            }
        }
    }
    c=(k-1)/n+1;
    if(c&1) r=(k-1)%n+1;
    else r=n-(k-1)%n;
    printf("%d %d\n",c,r);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int T=1;//scanf("%d",&T);
    while(T--) solve();
    return 0;
}
