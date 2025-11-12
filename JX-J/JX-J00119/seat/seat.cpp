#include <bits/stdc++.h>
using namespace std;
int a[105],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1];
    int xb;
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(a[i]==num) xb=i;
    }
    int sum=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                sum++;
                if(sum==xb) cout<<j<<" "<<i;
            }
        }
        if(j%2==0){
            for(int i=n;i>=1;i--){
                sum++;
                if(sum==xb) cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
