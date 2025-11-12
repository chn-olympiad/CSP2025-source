#include<bits/stdc++.h>
using namespace std;
int a[1005],n,m,x,y,R,b[105][105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    if(n%2==0){
        int cnt1=1;
        for(int i=1;i<=m;i+=2){
            for(int j=1;j<=n;j++){
                b[i][j]=cnt1;
                cnt1++;
            }
            for(int j=n;j>=1;j--){
                b[i+1][j]=cnt1;
                cnt1++;
            }
        }
    }
    else if(n%2!=0){
        int cnt2=1;
        for(int i=1;i<=m+1;i+=2){
            for(int j=1;j<=n;j++){
                b[i][j]=cnt2;
                cnt2++;
            }
            for(int j=n;j>=1;j--){
                b[i+1][j]=cnt2;
                cnt2++;
            }
        }
    }
  /*  for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<b[j][i]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+(n*m)+1);
    /*for(int i=1;i<=n*m;i++){
        cout<<a[i]<<" ";
    }*/
    int ans;
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            ans=n*m-i+1;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[j][i]==ans){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
