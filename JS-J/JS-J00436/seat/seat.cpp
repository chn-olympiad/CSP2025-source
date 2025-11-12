#include<bits/stdc++.h>
using namespace std;
int a[1005];
int b[1005][1005];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int x;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    x=a[0];
    sort(a,a+n*m,greater<int>());
    int cnt=0;
    for(int j=1;j<=m;j++){
        if(j%2!=0){
            for(int i=1;i<=n;i++){
                b[i][j]=a[cnt++];
            }
        }
        else{
            for(int i=n;i>=1;i--){
                b[i][j]=a[cnt++];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==x) {
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}

