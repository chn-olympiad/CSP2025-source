#include<bits/stdc++.h>
using namespace std;
int n,m,xiaoR;
int a[100];
bool cmp(int x,int y){return x>y;}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1)xiaoR=a[1];
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=m;i++){
        if(i%2==1){
            for(int j=1;j<=n;j++){if(a[(i-1)*n+j]==xiaoR){cout<<i<<" "<<j;return 0;}}
        }
        else {
            for(int j=n;j>=1;j--){if(a[i*n-j+1]==xiaoR){cout<<i<<" "<<j;return 0;}}
        }
    }
    return 0;
}
