#include<bits/stdc++.h>
using namespace std;
int n,m,guide[105],x,mc;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;++i)cin>>guide[i];
    x=guide[1];
    sort(guide+1,guide+n*m+1);
    for(int i=n*m;i>=1;--i)if(x==guide[i]){mc=n*m-i+1;break;}
    int l=mc/n,h=mc%n;
    if(h!=0)l++;
    if(h==0){
        cout<<l<<" "<<n;
    }else if(h!=0&&l%2==1){
        cout<<l<<" "<<h;
    }else if(h!=0&&l%2==0){
        cout<<l<<" "<<n-h+1;
    }
    return 0;
}
