#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m;
int a[111];
int b[11][11];
int c;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    memset(a,0,sizeof(a));
    cin>>n>>m;
    int k = n*m;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    c=a[0];
    sort(a,a+k,cmp);
    for(int i=0;i<=m;i+=2){
        for(int j=0;j<n;j++){
            b[i][j]=a[(i*n+j)];
        }
    }
    for(int i=1;i<=m;i+=2){
        int t = 0;
        for(int j=n-1;j>=0;j--){
            b[i][j]=a[(i*n+t)];
            t++;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(b[i][j]==c){
                cout<<i+1<<" "<<j+1;
            }
        }
    }
    
    return 0;
}