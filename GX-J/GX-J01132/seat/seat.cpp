#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int uv=0;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    sort(b+1,b+n*m+1,cmp);
    int cnt=0;
    for(int i=1;i<=m;i++){
        if(cnt%2==0){
            for(int j=1;j<=n;j++){
                a[i][j]=b[uv];
                uv++;
            }
        }
        if(cnt%2==1){
            for(int j=n;j>=1;j--){
                a[i][j]=b[uv];
                uv++;
            }
        }
        cnt++;
     }
     cnt=0;
     for(int i=1;i<=m;i++){
         if(cnt%2==0){
             for(int j=1;j<=n;j++){
                 if(a[i][j]==b[0]){
                     cout<<a[i][j];
                 }
              }
         }
         if(cnt%2==1){
             for(int j=n;j>=1;j--){
                 if(a[i][j]==b[0]){
                     cout<<a[i][j];
                 }
             }
         cnt++;
         }
     }
    return 0;
}
    
