#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],k,t=0;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
    if(i%2==1){
        for(int j=1;j<=n;j++){
            t++;
            if(a[t]==k){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }else{
        for(int j=n;j>=1;j--){
            t++;
            if(a[t]==k){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    }
    return 0;
}
