#include<bits/stdc++>
using namespace std;
int main(){
    freopen("seat.in",stdin);
    freopen("seat.out",stdout);
    int n,m;
    cin>>n>>m;
    int a[n][m];
    int ans[105]
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ans[i];
        }
    }
    if(ans[0]<=100 || ans[0]>=100-m){
        if(ans[0]=100){
            cout<<1<<" "<<1;
        }
        else{
            cout<<1<<" "<<2;
        }
    }
    return 0;
}
