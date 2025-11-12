#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,nm,a[110],r;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    nm=n*m;
    for(int i=1;i<=nm;i++){
        cin>>a[i];
    }
    r=a[1];
    sort(a+1,a+nm+1);
    int k=0;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                k++;
                if(a[nm-k+1]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        else{
            for(int j=n;j>=1;j--){
                k++;
                if(a[nm-k+1]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
