#include<bits/stdc++.h>
using namespace std;
int R,n,m,j,hj;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int gra[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>gra[i];
        if(i==1){
            j=gra[i];
            
        }
    }
    sort(gra,gra+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(gra[i]==j) {
        hj=i;
        break;}
    }
    int x=(hj+n-1)/n;
    if(x%2==1){
            if(hj%n==0)cout<<x<<' '<<n ;
            else cout<<x<<' '<<hj%n;
    }
    else if(x%2==0)cout<<x<<' '<<n-hj%n+1;
    return 0;
}
/*3 3
94 95 96 97 98 99 100 93 92*/
