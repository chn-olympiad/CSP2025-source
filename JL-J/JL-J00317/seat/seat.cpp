#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n,m,a[105],st[15][15],cnt;
bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    int t=a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int j=1;j<=m;j++){
        if(j%2==1){
            for(int i=1;i<=n;i++){
                st[i][j]=a[++cnt];
            }
        }
        else{
            for(int i=n;i>=1;i--){
                st[i][j]=a[++cnt];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(st[i][j]==t){
                cout << j <<" " <<i;
            }
        }
    }
    return 0;
}
