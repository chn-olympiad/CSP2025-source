#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int q[N],n,k,a[N],qm=0,ans;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    cin>>a[1];
    q[1]=a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
        q[i]=q[i-1]^a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=qm;j<=i;j++){
            int ll=q[i]^q[j];
            if(i!=j&&ll==k||(i==j&&a[i]==k)){
                qm=i;
                ans++;
                //cout<<i<<' '<<j<<' '<<k<<' '<<q[i]<<' '<<q[j]<<' '<<a[i]<<"\n";
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
