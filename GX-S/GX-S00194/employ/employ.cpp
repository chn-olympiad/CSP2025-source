#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define c(x) cout<<x<<"<"<<endl
#define mod 998244353
#define oll unsigned long long
using namespace std;
const int fet=510;
oll n,m;
string s;
int a[fet];

oll ksm(oll a,oll b){
    oll x=1;
    for(oll i=0;i<b;i++) x*=(a-i)%mod,c(a-i);
    return x;
}

int main(){
    oll ans=0;
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=0;i<n;i++) cin>>a[i];
    for(oll i=m;i<=n;i++){
        ans=(ans+ksm(n,i))%mod;
    }
    cout<<ans;
    return 0;
    //161088479
    //997046168
}

