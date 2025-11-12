#include <bits/stdc++.h>
using namespace std;
int n,m,c,r;
long long a[10000][10000],b[1][1];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        cin>>a[i][j];
        b[1][1]=a[1][1];
        }
    }
    sort(a,a+n*m+1,cmp);

    return 0;
}
