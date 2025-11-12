#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n,m,a[101]={},b[11][11]={};
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cj=a[1],bj=0,p=0;
    sort(a+1,a+1+n*m,cmp);
    for(int j=1;j<=m;j++){
        if(bj==0){
            for(int i=1;i<=n;i++){
                p++;
                if(a[p]==cj){
                    cout<<j<<" "<<i;
                }
            }
            bj=1;
        }
        else{
            for(int i=n;i>=1;i--){
                p++;
                if(a[p]==cj){
                    cout<<j<<" "<<i;
                }
            }
            bj=0;
        }
    }
    return 0;
}
