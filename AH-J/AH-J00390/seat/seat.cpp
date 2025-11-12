#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000],num,t,i,j;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n*m;i++){
        cin>>a[i];
    }
    num=a[1];
    sort(a+1,a+1+n*m);
    t=n*m;
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(a[t]==num){
                cout<<i<<" "<<j;
                break;
            }
            t--;
        }
        if(a[t]==num){
            break;
        }
    }
    return 0;
}
