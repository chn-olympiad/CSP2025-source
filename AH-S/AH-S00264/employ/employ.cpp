#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[1000005];
string s;
long long ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++){
	cin>>a[i];
    }
    for(int i=n;i>=1;i--){
	ans=ans*i%mod;
    }
    cout<<ans<<endl;
    return 0;
}
