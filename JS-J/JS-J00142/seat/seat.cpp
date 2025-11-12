#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    int w,a,cnt=1;
    cin>>a;
    for(int i=2;i<=n*m;i++){
        cin>>w;
        if(a<w)cnt++;
    }
    int d=cnt/n,mod=cnt%n;
    if(mod)d++;
    if(d%2){
        cout<<d<<" "<<mod;
    }
    else{
        cout<<d<<" "<<n-mod+1;
    }
    return 0;
}
