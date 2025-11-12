#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[105];
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int cnt=a[1];
    sort(a+1,a+(n*m)+1,cmp);
    int s[12][12];
    for(int i=1;i<=m;i++){
        if(i%2!=0){
            for(int j=1;j<=n;j++){
                s[i][j]=a[n*(i-1)+j];
            }
        }
        else{
            for(int j=n;j>=1;j--){
                s[i][j]=a[n*(i-1)+n-j+1];
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]==cnt){
                cout<<i<<" "<<j;
                return 0;
            }
        }
    }
}
