#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,k,cnt,a[N];
bool f;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    f=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) f=0;
        if(a[i]==1) cnt++;
    }
    if(f)
        if(k==0) cout<<cnt/2;
        else cout<<cnt;
    return 0;
}
