#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    int man=b[1];
    sort(b+1,b+n*m+1);
    for(int i=1;i<=((n*m)/2);i++){
        swap(b[i],b[n*m-i+1]);
    }
    int p=1,sum=1;
    for(int i=1;i<=m;i++){
        if(p==1){
            for(int j=1;j<=n;j++){
                a[i][j]=b[sum];
                sum++;
            }
            p=0;
        }
        else{
            for(int j=n;j>=1;j--){
                a[i][j]=b[sum];
                sum++;
            }
            p=1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[j][i]==man){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
