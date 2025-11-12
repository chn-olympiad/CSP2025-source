#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,k,a[N];
int cnt;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        if(a[i]==0) cnt++;
    }
    if(k==0) {
        for(int i=1;i<=n;i++) {
            if(a[i]==1 && a[i+1]==1) {
                cnt++;
                i++;
            }
        }
        cout<<cnt;
    }
    else {
        cnt=0;
        for(int i=1;i<n;i++) {
            if(a[i]==0 && a[i+1]==1 || a[i]==1 && a[i+1]==0) {
                cnt++;
                i++;
            }
        }
        cout<<cnt;
    }
    return 0;
}
