#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],ans,cnt=0;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    ans=a[1];
    sort(a+1,a+n*m+1);
    reverse(a+1,a+n*m+1);
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                cnt++;
                if(a[cnt]==ans){cout<<i<<' '<<j;}
            }
        }
        if(i%2==0){
            for(int j=n;j>=1;j--){
                cnt++;
                if(a[cnt]==ans){cout<<i<<' '<<j;}
            }
        }
    }
    return 0;
}
