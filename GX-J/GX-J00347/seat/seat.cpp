#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],k,c;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int t=n*m;
    for(int i=1;i<=t;i++){
        cin>>a[i];
    }
    k=a[1];
    sort(a+1,a+t+1);
    for(int i=1;i<=t;i++){
        if(a[i]==k){
            c=i;
            break;
        }
    }
    c=t-c+1;
    int p=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
           for(int i=1;i<=n;i++){
               p++;
               if(p==c){
                cout<<j<<" "<<i;
                return 0;
               }
           }
        }else{
            for(int i=n;i>=1;i--){
               p++;
               if(p==c){
                cout<<j<<" "<<i;
                return 0;
               }
           }
        }
    }
    return 0;
}
