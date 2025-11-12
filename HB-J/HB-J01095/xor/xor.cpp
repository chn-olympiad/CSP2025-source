#include <bits/stdc++.h>
using namespace std;
const int SIZE=5e5;
//define int long long
int n,k,z,l,Size,r,ans,a[SIZE+1],_a[SIZE+1];
bool f[SIZE+1],flag;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int i;
    cin>>n>>k;
    for(i=1;i<=n;i++) cin>>a[i];
    _a[0]=z=0;
    for(i=1;i<=n;i++){
        z^=a[i];
        _a[i]=z;
    }
    for(Size=0;Size<n;Size++){
        for(l=1;l<=n;l++){//l<=r&&r<=n
            r=l+Size;
            if(r>n) break;
            for(i=l,flag=1;i<=r;i++) if(f[i]){flag=0;break;}
            if(!flag) continue;
            if((_a[l-1]^_a[r])==k){
                ans++;
                //cout<<l<<' '<<r<<endl;
                for(i=l;i<=r;i++) f[i]=1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
