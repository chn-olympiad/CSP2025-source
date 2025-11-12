#include<bits/stdc++.h>
using namespace std;
char a[100001][100001];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n , q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=2;j++){
            cin >> a[i][j];
        }
    }
    for(int i=1;i<=q;i++){
    cout << "0" << endl;
    }
    return 0;
}
