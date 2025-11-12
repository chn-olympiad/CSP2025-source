#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int l[107];
int dp[12][12];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
       cin>>l[i];
    }
    int r=l[1];
    sort(l+1,l+n*m+1);
    reverse(l+1,l+n*m+1);
    int p=1;
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                if(l[p]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                p++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(l[p]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
                p++;
            }
        }

    }
    return 0;
}
