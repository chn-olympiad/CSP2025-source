#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=1e5+10;
const int Z=998244353;
int n,m,a[N],mx;
ll ans=1;
string s;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        a[x]++;
        mx=max(mx,x);
    }
    for(int i=0;i<=mx;i++){
        if((ll)a[i]) ans*=(ll)a[i]%Z;
        ans%=Z;
    }
    cout<<ans;
    return 0;
}
