#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,r;
    cin>>n>>m;
    int a[1005][1005];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    r=a[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==n-1&&j==m-1){
                break;
            }
            if(a[i][j]>a[i][j+1]){
                swap(a[i][j],a[i][j+1]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==r){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    return 0;
}
