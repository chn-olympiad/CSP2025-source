#include<bits/stdc++.h>
using namespace std;
int n,m,t;
void solve(){
    scanf("%d %d",&n,&m);
    while(n>0){
        t++;
        n-=m;
    }
    printf("%d %d",t,n+m);
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    solve();
    return 0;
}