#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],xr,pm;
bool cmp(int x,int y){return x>y;}
int c,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i) cin>>a[i];
    xr=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;++i){
        if(a[i]==xr){
            pm=i;
            break;
        }
    }
    c=(pm+n-1)/n;
    r=(c&1?(pm%n==0?n:pm%n):n-(pm%n==0?n:pm%n)+1);
    cout<<c<<' '<<r;
    return 0;
}
