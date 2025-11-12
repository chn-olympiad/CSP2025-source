#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[5009];
long long sum,cnt;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int j=3;j<=n;j++){
        for(int i=1;i<=n;i++){
            int cnt1=0,cnt2=1;
            if(a[i]+a[i]+(++cnt1)]+a[i+(++cnt2)]>2*max(max(a[i],a[i+(++cnt1)]),a[i+(++cnt2)])){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
