#include<bits/stdc++.h>
using namespace std;
int n,m,xn,a[110],k,ansx,ansy;
bool cmp(int xn,int yn){
    return xn>yn;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    xn=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==xn){
            k=i;
            break;
        }
    }
    int k1=k/(2*n);
    int k2=k%(2*n);
    if(k2==0){
        ansx=1;
        ansy=2*k1;
    }
    if(k2<=n&&k2!=0){
        ansx=k2;
        ansy=2*k1+1;
    }
    if(k2>=n){
        ansx=2*n-k2+1;
        ansy=2*k1+2;
    }
    cout<<ansy<<" "<<ansx<<endl;
    return 0;
}
