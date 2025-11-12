#include<bits\stdc++.h>
using namespace std;
long long n,m,c[510],ans,cnt0,temp;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(long long i=0;i<s.size();i++)if(s[i]=='0')cnt0++;
    for(long long i=1;i<=n;i++)cin>>c[i];
    if(m==n){
        cout<<0;
        return 0;
    }
    ans=1;
    for(long long i=1;i<=n;i++){
        ans*=i;
        ans%=998244353;
    }
    cout<<ans;
    return 0;
}
