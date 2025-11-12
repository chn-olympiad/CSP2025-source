#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1010],sum,ans=1;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0) sum++;
    }
    for(long long i=1;i<=sum;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
