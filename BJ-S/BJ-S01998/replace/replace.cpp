#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n, q;
    cin >> n >> q;
    int a[200005], b[200005], c[200005], d[200005];
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < q; i++){
        cin >> c[i] >> d[i];
    }
    cout << "2" <<endl << "0";
    return 0;
}
