#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c,r;
    cin>>c>>r;
    int n[c+1][r+1];
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            cin>>n[i][j];
        }
    }
    int b=n[1][1];
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            if(n[i][j]>n[i+1][j+1]){
                swap(n[i][j],n[i+1][j+1]);
            }
        }
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<=r;j++){
            if(n[i][j]==b){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
    return 0;
}
