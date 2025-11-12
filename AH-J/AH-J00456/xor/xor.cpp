#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<int> a(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    if(k==0)cout<<n/2;
    else if(k<=1){
            int ans=0;
    int sum=0;
        for(int i=0;i<n;i++){
            if(a[i]==1)sum++;
            else ans++;
        }
        cout<<max(sum,ans);
    }
    return 0;
}

