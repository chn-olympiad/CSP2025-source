#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long n,k,ans=0;
    cin>>n>>k;
    long long a[n+1];
    //int i=0;
    bool A=1,B=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
        int i=1;
        long long cnt=0;
        while(i<=n){
            cnt^=a[i];
            if(cnt==k){
                ans++;
                cnt=0;
            }
            i++;
        }
    // }
    cout<<ans;
}
