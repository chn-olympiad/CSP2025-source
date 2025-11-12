#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
long long ans=0,cnt;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) {
        cnt=a[i];
        for(int j=1;j<=n;j++) {
            if(i==j && a[i]==k) {
                ans++;
            } else {
                for(int g=i+1;g<=j;g++) {
                    cnt^=a[i];
                }
                if(cnt==k) {
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
