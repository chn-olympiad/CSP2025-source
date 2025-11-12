#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,x,nn=1,mm=1,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    for(int i=2;i<=n*m;i++){
        cin>>x;
        a[x]++;
    }
    for(int i=100;i>=r;i--){
        if(a[i]) mm+=a[i];
        if(mm>m){
            nn+=mm/m;
            mm=mm%m;
        }
    }
    if(n%2==1){
        cout<<nn<<" "<<mm;
    }else{
        cout<<nn<<" "<<m-mm+1;
    }
    return 0;
}
