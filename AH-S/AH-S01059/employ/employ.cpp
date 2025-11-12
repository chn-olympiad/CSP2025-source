#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,ans=1,p=998244353;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>s;
    for(int i=1,x;i<=n;i++) cin>>x;
    for(int i=1;i<=n;i++) ans=ans*i%p;
    cout<<ans;
    return 0;
}
