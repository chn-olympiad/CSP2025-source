#include<bits/stdc++.h>
using namespace std;
long long a[500005],yhh[500005];
long long n,k;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        yhh[i]=yhh[i-1]^a[i];
    }
    long long ans=0,now=1;
    int l=1;
    while(l<=n){
        for(int r=l;r<=n;r++){
            long long x=yhh[r]^yhh[l-1];
            if(x==k){
                ans++;
                l=r+1;
                break;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
