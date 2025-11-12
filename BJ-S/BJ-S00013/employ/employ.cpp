#include <bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
int n,m;
string s;
int c[N];
int num;
long long ans;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0;i<s.size();i++)
        if(s[i]=='0') num++;
    if(num==0){
        ans=1;
        for(int i=n;i>=2;i--) ans=ans*i%mod;
    }
    else if(m==n) ans=0;
    else if(m<num) ans=0;
    cout<<ans;
    return 0;
}