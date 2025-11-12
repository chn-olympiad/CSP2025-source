#include<bits/stdc++.h>
using namespace std;
int a[11][11];
int b[200];
int n,m,r;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    r = b[1];
    sort(b+1,b+n*m+1,cmp);
    int cnt=1;
    for(int i=1;i<=m;i++){
        if(i%2==1){
           for(int j=1;j<=n;j++){
               a[j][i]=b[cnt];
               cnt++;
               if(a[j][i] == r){
                cout<<i<<" "<<j;
                return 0;
               }
           }
        }
        if(i%2==0){
           for(int j=n;j>=1;j--){
               a[j][i]=b[cnt];
               cnt++;
               if(a[j][i] == r){
                cout<<i<<" "<<j;
                return 0;
               }
           }
        }
    }



    return 0;
}


