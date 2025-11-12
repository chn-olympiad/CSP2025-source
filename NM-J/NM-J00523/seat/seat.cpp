#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat,out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long as[n*m];
    for(long long i=1;i<=n*m;i++){
        cin>>as[i];
    }
    long long xm=as[1];
    for(long long i=1;i<=m*n;i++){
        for(long long j=i+1;j<=m*n;j++){
            if(as[i]<as[j]){
                swap(as[i],as[j]);
            }
        }
    }
    for(long long i=1;i<=n*m;i++){
        if(as[i]==xm){
            xm=i;
            break;
        }
    }
    if(xm==1){
        cout<<1<<" "<<1;
    }
    else{
        if(xm%m==0){
            cout<<xm/m<<" "<<m;
        }
        else{
            if((xm/m+1)%2==1){
                cout<<xm/m+1<<" "<<xm%m;
            }
            else{
                cout<<xm/m+1<<" "<<m-xm%m;
            }
        }
    }
    return 0;
}
