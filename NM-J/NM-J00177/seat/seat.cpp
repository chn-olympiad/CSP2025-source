#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[115], pos[15][15], ans, tmp=1;
bool cmp(int x, int y){
     return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    ans=a[1];
    sort(a+1, a+(n*m)+1, cmp);
    for(int i=1; i<=m; i++){
        if(i%2==0){
            for(int j=n; j>=1; j--){
                pos[i][j]=a[tmp++];
            }
        }else{
            for(int j=1; j<=n; j++){
                pos[i][j]=a[tmp++];
            }
        }
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(pos[i][j]==ans){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
