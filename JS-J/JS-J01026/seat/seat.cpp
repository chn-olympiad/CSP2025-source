#include<iostream>
#include<algorithm>
using namespace std ;
const int MAXN=12*12;
typedef long long ll ;
ll n,m,c[MAXN],st=0,pm,myc;
bool cmp(ll a,ll b){return a>b;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m ;
    for(int i=1;i<=n*m;i++) cin >> c[i] ;
    myc=c[1];
    sort(c+1,c+n*m+1,cmp);
    for(int i=1;i<=n*m;i++) if(c[i]==myc) pm=i;
    for(int x=1;x<=n;x++){
        if(x%2==1){
            for(int y=1;y<=m;y++){
                st++;
                if(st==pm&&c[st]==myc) cout << x << ' ' << y ;
            }
        }
        else{
            for(int y=m;y>=1;y--){
                st++;
                if(st==pm&&c[st]==myc) cout << x << ' ' << y ;
            }
        }
    }
    return 0 ;
}
