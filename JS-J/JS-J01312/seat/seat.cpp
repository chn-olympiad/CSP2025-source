#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N],n,m;
int pos,c[N][N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n*m;i++) cin >> a[i];
    pos = a[1];
    sort(a+1,a+n*m+1,greater<>());
    int k = 1;
    for(int j = 1;j <= m;j++){
        if(j&1){
            for(int i = 1;i <= n;i++) c[i][j] = a[k++];
        }else{
            for(int i = n;i >= 1;i--) c[i][j] = a[k++];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            if(c[i][j] == pos){
                cout << j << " " << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}
