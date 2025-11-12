#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int aR=a[1];
    for(int i=1;i<n*m;i++){
        for(int j=1;j<=n*m-i;j++){
            if(a[i]<a[i+j])swap(a[i],a[i+j]);
        }
    }
    int num=0;
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                num++;
                if(a[num]==aR){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
        else{
            for(int i=n;i>=1;i--){
                num++;
                if(a[num]==aR){
                    cout<<j<<' '<<i;
                    return 0;
                }
            }
        }
    }
    return 0;
}
