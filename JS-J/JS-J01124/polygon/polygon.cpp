#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int a[N];

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    int maxn = 0;
    int minn = 0;
    int sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        sum += a[i];
        maxn = max(maxn,a[i]);
        minn = min(minn,a[i]);
    }
    if(sum - maxn - minn + minn > maxn){
        cout << 1 << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}
