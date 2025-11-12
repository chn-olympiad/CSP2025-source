#include <bits/stdc++.h>
using namespace std;
int sc[111];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a;
    cin >> n >> m;
    cin >> a;
    sc[1]=a;
    for (int i=2;i<=n*m;i++) cin >> sc[i];
    sort(sc+1,sc+n*m+1);
    for (int i=1;i<=m;i++){
        if (i%2){
            for (int j=1;j<=n;j++){
                if (sc[n*(i-1)+j]==a){cout << i << j;return 0;}}}
        else {
            for (int j=n;j>=1;j--){
                if (sc[n*i-(n-j+1)]==a){cout << i << j;return 0;}}}}
    return 0;}
