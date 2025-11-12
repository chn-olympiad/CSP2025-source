#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","r",stdout);
    ios::sync_with_stdio(false);
    int n,m,a[105],b[105];
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
        for(int j=1;j<=n*m;j++){
            if(a[i+1]>a[i]){
                b[j]=a[i];
            }
        }
    }
    for(int j=1;j<=n*m;j++){
        int v=j-j/n;
        if(b[j]==a[1]){
            if(j<=n){
                cout << 1 << " " << j;
            }
            else{
                if(j%n>0){
                    cout << j/n+1 << " " << v*n;
                }
                else{
                    cout << j/n << " " << n;
                }
            }
        }
    }
    return 0;
}
