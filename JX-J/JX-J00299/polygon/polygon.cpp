#include <bits/std++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int m;
        cin >> m;
        ans += m;
    }
    return 0;
}
