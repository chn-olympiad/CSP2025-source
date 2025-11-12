#include "bits/stdc++.h"
#define int long long
using namespace std;
int a[15][15],n,m;
int b[10010];
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int q=b[1];
    sort(b+1,b+n*m+1,cmp);
    int k=1,i=1,l=1;
    while(l<=m){
        if(l%2==1){
            i=1;
            while(i<=n){
                a[i][l]=b[k];
                k++;
                i++;
            }
        }else{
            i=n;
            while(i>=1){
                a[i][l]=b[k];
                k++;
                i--;
            }
        }
        l++;
    }
    for(int i=1;i<=n;i++){
        for(int l=1;l<=m;l++){
            if(a[i][l]==q){
                cout<<l<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
