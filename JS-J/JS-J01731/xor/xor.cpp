#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[200005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1;
    while(l<=n&&r<=n){
        int x=0;
        if(l==r) x=a[l];
        else{
            for(int i=l;i<=r;i++) x^=a[i];
        }
        if(x==k){
            ans++;
            l=r+1;
            r=l;
            continue;
        }
        r++;
    }
    cout<<ans<<endl;
    return 0;
}
