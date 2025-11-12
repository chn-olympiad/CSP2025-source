#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long c,r,s,a[105],b[105],dp[105][105],num=1;
    cin>>c>>r;
    for(int i=1;i<=c*r;i++){
        cin>>b[i];
    }
    s=b[1];
    sort(b+1,b+c*r+1);
    for(int i=1;i<=c*r;i++){
        a[i]=b[c*r-i+1];
    }
    for(int i=1;i<=r;i++){
        if(i%2==1){
            for(int j=1;j<=c;j++){
                dp[j][i]=a[num++];
            }
        }else{
            for(int j=c;j>0;j--){
                dp[j][i]=a[num++];
            }
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            if(dp[i][j]==s){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
