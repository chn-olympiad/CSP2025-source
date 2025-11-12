#include<bits/stdc++.h>
using namespace std;
int fun(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,arr[201],R,k=0;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>arr[i];
    }
    R=arr[0];
    sort(arr,arr+n*m,fun);
    int map[12][12];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            map[j+1][i+1]=arr[j+i*n];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(map[i][j]==R){
                cout<<j<<" "<<i;
            }
        }
    }
    return 0;
}
