#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5;
int n,k,a[N+10];
signed main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int x1=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) x1++;
        if(x1!=0&&x1%2==k) ans++,x1=0;
    }
    cout<<ans<<"\n";
    return 0;
}
//#Shang4Shan3Ruo6Shui4