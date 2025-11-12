#include<bits/stdc++.h>
using namespace std;
int n,m,nm,a[105],xr,s;
bool z;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    cin>>a[0];
    xr=a[0];
    for(int i=1;i<nm;i++){
        cin>>a[i];
    }
    sort(a,a+nm,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(xr==a[s]){
                    cout<<i<<" "<<j;
                    return 0;
                }
                s++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(xr==a[s]){
                    cout<<i<<" "<<j;
                    return 0;
                }
                s++;
            }
        }
    }
    return 0;
}
