#include<bits/stdc++.h>
using namespace std;
int a[20][20],s[110],n,m,q;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>s[i];
    }
    q=s[1];
    sort(s+1,s+n*m+1);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                for(int k=(m-i+1)*n,k>=0;k++){
                    a[i][j]=s[k];
                }
            }
        }else{
            for(int i=n;i>=1;i--){
                for(int k=(m-i+1)*n,k>=0;k++){
                    a[i][j]=s[k];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]==p){
                cout<<i<<' '<<j;
            }
        }
    }
    return 0;
}
