#include<bits/stdc++.h>
using namespace std;
#define int long long
int fen[10010];
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>fen[i];
    int d=fen[1];
    int x,y;
    sort(fen+1,fen+n*m+1);
    for(int i=1;i<=n*m;i++) if(fen[i]==d) x=i;
    int b=ceil(x/n);
    if(b%2==1) y=x-(b-1)*n;
    else y=1+(b*n-x);
    cout<<b<<" "<<y;
    return 0;
}
