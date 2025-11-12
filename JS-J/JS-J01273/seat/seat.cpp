#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
int a[21][21],b[102],l;
int n,m;
cin >> n>>m;
l=n*m;
for(int i = 1;i<=n*m;i++){
    cin >> b[i];
}
int o=b[1];
sort(b+1,b+n*m+1);
for(int j  =1;j<=m;j++){
        if(j%2==0){
        for(int i = n;i>=1;i--){
                a[i][j]=b[l];
                l--;
        }
        }else{
            for(int i = 1;i<=n;i++){
                a[i][j]=b[l];
                l--;
            }
        }


}
for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
           if(a[i][j]==o){
            cout << j<<" "<<i;
            break;
           }
        }
}
    return 0;
}
