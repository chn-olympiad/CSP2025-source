#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],k;
int ans,s[N],f[N],lst[1<<20];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]^=k;
        s[i]=s[i-1]^a[i];
    }
    if(n<=2){
        int ans=0;
        if(a[1]^k^a[2]^k==k) ans++;
        if(a[1]^k==k) ans++;
        if(a[2]^k==k)ans++;
        cout<<ans;
        return 0;
    }
    for(int i=1;i<=n;i++){
        if(lst[s[i]]!=0) {
            f[i]=max(f[i-1],f[lst[s[i]]-1]+1);
        }
        else f[i]=f[i-1];
        lst[s[i]]=i;
    }
    cout<<f[n];
    return 0;
}
