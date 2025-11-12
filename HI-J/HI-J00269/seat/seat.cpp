#include <bits/stdc++.h>
using namespace std;
int a[105],n,m;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n*m;i++) cin >> a[i];
    int p=a[1];
    sort(a+1,a+n*m+1,greater<int>());
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[n*(i-1)+j]==p){
                cout << i << ' ' << (i&1?j:n-j+1);
                return 0;
            }
        }
    }
    return 0;
}
