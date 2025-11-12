#include <bits/stdc++.h>
using namespace std;
int a[12][12],b[114];
int main(){
    freopen("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    int m,n,R,num=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    R=b[1];
    for(int i=1;i<=n*m;i++){
        for(int j=i+1;j<=n*m;j++){
            if(b[i]<b[j]){
                int t=b[i];
               b[i]=b[j];
              b[j]=t;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[j][i]=b[num++];

            }
        }
        else{
            for(int j=n;j>0;j--){
                a[j][i]=b[num++];

            }
        }
    }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i][j]==R){
                   cout<<j<<" "<<i;
                   break;
                }
            }
        }
    return 0;
}
