#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, sum;
int a1[100005], a2[100005], a3[100005];
signed main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 0; i <= n; i++) {
            a1[i]=a2[i]=a3[i]=0;
        }
        m = sum = 0;
        for(int i = 1; i <= n; i++) {
            cin>>a1[i]>>a2[i]>>a3[i];
        }
        m = n/2;
        sort(a1+1, a1+1+n);
//        cout<<m<<" "<<n-m<<endl;
//        for(int i = 1; i <= n; i++) cout<<a1[i]<<" ";
//        cout<<endl;
        for(int i = n; i >= n-m+1; i--) {
            sum += a1[i];
        }
        cout<<sum<<endl;
    }
    return 0;
}
