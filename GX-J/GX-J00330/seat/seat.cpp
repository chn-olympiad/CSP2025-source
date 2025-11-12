#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int a[100][100],b[100],n,m,s=1,c;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>b[i];
    }
    c=b[1];
    for(int i=1;i<=n*m;i++){
        if(b[i]<b[i+1])swap(b[i],b[i+1]);
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                a[i][j]=b[s];
                s++;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                a[i][j]=b[s];
                s++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){
                if(c==a[i][j])cout<<i<<" "<<j;
            }
        }
        else{
            for(int j=n;j>=1;j--){
                if(c==a[i][j])cout<<i<<" "<<j;
            }
        }
    }
    return 0;
}
