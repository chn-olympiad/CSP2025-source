#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
bool p=1;
int n;
long long k,a[N];
int main() {
    freopen("xor.in", "r", stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i=1; i<=n; i++) cin >> a[i];
    for(int i=1; i<=n; i++) if(a[i]>=2) p=0;
    if(n<=2&& k==0&&p) {
        cout << 1;
    }else if(k==1&&p) {
        int cnt1=0,cnt0=0;
        for(int i=1; i<=n; i++) {
            if(a[i]==0) cnt0++;
            else cnt1++;
        }
        cout << cnt1;
    }else if(k==0&&p) {
        a[0]=3;
        int cnt1=0,cnt0=0,sum=0;
        for(int i=1; i<=n; i++) {
            if(a[i]==0) cnt0++,sum=(cnt1+1)/2,cnt1=0;
            else if(a[i-1]==a[i]&&a[i]==1) cnt1++;
        }
        sum=(cnt1+1)/2;
        cout << cnt0+sum;
    }else {
        ll l=1,num=a[1],ans=0;
        for(int i=2; i<=n; i++) {
            if(num != k) num^=a[i];
            else ans++,l=i,num=a[i];
        }
        if(num==k) ans++;
        cout << ans;
    }
    return 0;
}
