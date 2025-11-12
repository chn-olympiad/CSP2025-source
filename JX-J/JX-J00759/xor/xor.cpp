#include <bits/stdc++.h>

using namespace std;
const int N = 5e5+2;
long long a[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.ans","w",stdout);
    int n,m,ans=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        ans=a[1] xor a[2];
    }
    cout <<ans;
    return 0;
}
