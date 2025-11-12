#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    long long n,k;
    cin>>n>>k;
    long long a[n],sum[n];
    for(long long i=0;i<n;i++) {
        cin>>a[i];
        if(i==0) sum[i]=a[i];
        else sum[i]=sum[i-1]^a[i];
    }
    long long tot=0;
    set<long long> st;
    st.insert(k);
    for(long long i=0;i<n;i++) {
        if(st.count(sum[i])) {
            tot++;
            st.clear();
        }
        st.insert(k^sum[i]);
    }
    cout<<tot;
    return 0;
}