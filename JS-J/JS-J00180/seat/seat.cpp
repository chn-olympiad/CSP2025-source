#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cnt=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>a[0][0]){
                cnt++;
            }
        }
    }
    int num=cnt/n;
    if(cnt%n==0){
        cout<<num;
    }else{
        cout<<num+1;
        num++;
    }
    cout<<" ";
    if(num&1){
        if(cnt%n==0){
            cout<<n;
        }else{
            cout<<cnt%n;
        }
    }else{
        if(cnt%n==0){
            cout<<1;
        }else{
            cout<<n-cnt%n+1;
        }
    }
    return 0;
}
