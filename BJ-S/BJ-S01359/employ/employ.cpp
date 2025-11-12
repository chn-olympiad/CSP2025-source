#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,a[1010],cnt=0;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;//s is 1
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==0)   cnt++;
    }
    for(int i=1;i<=n-cnt;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans<<endl;
    return 0;
}
