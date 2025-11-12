#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e3+10;
int n,m,R;
int a[N],mp[20][20];
bool cmp(int x,int y){
    return x>y;
}
int cnt=0,ansx=0,ansy=0;
void solve(){
    int x=1,y=1;
    bool f=1;//up0,down1;
    while(x<=n&&y<=m){
        ++cnt;//mp[x][y]=a[cnt];
        // printf("%lld\n%lld %lld\n",mp[x][y],x,y);
        if(a[cnt]==R){
            ansx=x,ansy=y;
            return ;
        }
        if((f&&(x==n))||(!f&&(x==1))){
            f=!f;
            y++;
        }else{
            if(f){
                x++;
            }else{
                x--;
            }
        }
    }
    return ;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n*m;i++){
        scanf("%lld",&a[i]);
        if(i==1)R=a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    solve();
    printf("%lld %lld\n",ansy,ansx);
    return 0;
}