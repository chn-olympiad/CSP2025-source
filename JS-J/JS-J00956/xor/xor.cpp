#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,a[N],ans,v[N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        ll l=a[i];
        for(int j=i;j<=n;j++){
            if(j!=i) l=l^a[j];
            if(l==k){
                for(int k=i;k<=j;k++) v[k]++;
                ans++;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
            if(v[i]>1) ans=ans-v[i]+1;
    cout<<ans;
    return 0;
}
