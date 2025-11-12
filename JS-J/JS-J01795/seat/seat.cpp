#include<bits/stdc++.h>
using namespace std;
const int N=210;
int n,m,k,a[N],cnt;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    k=a[1];
    cnt=n*m;
    sort(a+1,a+1+n*m);
    for(int i=1;i<=m;i++){
        if(i%2==1){
          for(int j=1;j<=n;j++){
            if(a[cnt]==k){
                cout<<i<<" "<<j;
                return 0;
                }
            cnt--;
            }
        }
        else{
            for(int j=n;j>=1;j--){
            if(a[cnt]==k){
                cout<<i<<" "<<j;
                return 0;
            }
            cnt--;
            }
        }
    }
    return 0;
}
