#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[125],b[15][15];

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n*m; i++){
        cin>>a[i];
    }
    int ans=a[1];
    sort(a+1,a+1+n*m,cmp);
    int cnt=0;
    for(int j=1; j<=m; j++){
        if(j%2==0){
            for(int i=n; i>0; i--){
                cnt++;
                b[i][j]=a[cnt];
            }
        }else{
            for(int i=1; i<=n; i++){
              cnt++;
                b[i][j]=a[cnt];
            }
        }
    }

    int c=0,r=0;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(b[i][j]==ans){
                c=j,r=i;
            }
        }
    }
    cout<<c<<" "<<r;

    return 0;
}