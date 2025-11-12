#include<bits/stdc++.h>
using namespace std;
int a[1005],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,s,flag=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        s=a[1];
    }
    sort(a+1,a+1+n*m,greater<int>());
    for(int i=1;i<=n*m;i++){
        if(flag==1){
            if(i%n==0){
                b[n][i/n]=a[i];
                flag=0;
            }else{
                b[i%n][i/n+1]=a[i];
            }
        }else{
            if(i%n==0){
                b[1][i/n]=a[i];
                flag=1;
            }else{
                b[n-i%n+1][i/n+1]=a[i];
            }
        }
    }
    int ac=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==s){
                cout<<j<<" "<<i;
                ac=1;
                break;
            }
        }
        if(ac==1){
            break;
        }
    }
    return 0;
}
