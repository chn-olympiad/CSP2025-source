#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e3+5,M=998244353;
int n,a[N],s[N];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<3){
        cout<<0;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    if(a[1]+a[2]>a[3]) cout<<1;
    else cout<<0;
    return 0;
}
