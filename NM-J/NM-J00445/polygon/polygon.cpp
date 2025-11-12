#include<bits/stdc++.h>
using namespace std;
int n,ans,maxn,a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        ans+=a[i];
        maxn = max(maxn,a[i]);
    }
    if(n >= 3 && ans > 2*maxn){
        cout << 1;
    }
    else{
        cout << 0;
    }
    return 0;
}
