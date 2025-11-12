#include <bits/stdc++.h>
using namespace std;
long long a[10005],n,k,s,l=1,r=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(long long i=1,f=0;i<=n;i++){
        cin>>a[i];
        f^=a[i];
        if(f==k||a[i]==k){
            s++;
            l=r+1;
            r=l;
            f=0;
        }
        r++;
    }
    cout<<s;
    return 0;
}
