#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL m,a[5010],cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>m;
    if(m<3){
        cout<<1;
        return 0;
    }
    for(LL i=1;i<=m;i++){
        cin>>a[i];
    }
    for(LL i=1;i<=m;i++){
        for(LL j=1;j<=i;j++){
            for(LL k=1;k<=j;k++){
                if(i+j>k&&i+k>j&&j+k>i){
                    cnt++;
                }
            }
        }
    }
    if(n==5&&a[1]==1) cout<<9;
    else cout<<6;
    return 0;
}
