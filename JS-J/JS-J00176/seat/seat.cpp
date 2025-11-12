#include<bits/stdc++.h>
using namespace std;
int n,m,place,c,r,p,q,a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>=a[1]) place++;
    }
    p=place/n;q=place%n;
    if(p%2){
        if(q){c=p+1;r=n-q+1;}
        else{c=p;r=n;}
    }
    else{
        if(q){c=p+1;r=q;}
        else{c=p;r=1;}
    }
    cout<<c<<' '<<r;
    return 0;
}
