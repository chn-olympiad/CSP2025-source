#include<bits/stdc++.h>
using namespace std;
bool cmp(int o,int p){
    if(o>=p) return o>=p;
    else return o>p;
}
int s;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int all=n*m;
    int a[all]={},b[n][m]={};
    for(int i=1;i<=all;i++) cin>>a[i];
    s=a[1];
    sort(a+1,a+all+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            b[i][j]=a[(i-1)*n+j];
        }
    }
    for(int i=2;i<=n;i+=2) sort(b[i]+1,b[i]+m+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(b[i][j]==s){
                cout<<i<<" "<<j;
                break;
            }
        }
    }
    return 0;
}
