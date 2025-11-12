#include <bits/stdc++.h>
using namespace std;
int n,m,r,k;
int a[105];
int arr[13][13];
bool sor(int a,int b){
    if(a<b) return false;
    return true;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>r;
    a[0]=r;
    for(int i=1;i<n*m;i++){
        cin>>a[i];
    }
    sort(a,a+(n*m),sor);
    for(int j=1;j<=m;j++){
        if(j%2!=0){
            for(int i=1;i<=n;i++){
                arr[i][j]=a[k];
                k++;
            }
        }else if(j%2==0){
            for(int i=n;i>=1;i--){
                arr[i][j]=a[k];
                k++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]==r){
                cout<<j<<" "<<i<<endl;
            }
        }
    }
    return 0;
}
