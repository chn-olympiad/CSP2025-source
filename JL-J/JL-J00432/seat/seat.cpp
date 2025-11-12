#include<bits/stdc++.h>
using namespace std;
int a[15][15],n,m,ans,sum[105],r,num;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>sum[i];
    }
    r=sum[1];
    sort(sum+1,sum+n*m+1);
    for(int i=n*m;i>=1;i--){
        if(sum[i]==r){
            r=n*m-i+1;
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==0){
            for(int j=n;j>=1;j--){
                num++;
                if(num==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        if(i%2==1){
            for(int j=1;j<=n;j++){
                num++;
                if(num==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
    }
    return 0;
}
