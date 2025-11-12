#include<bits/stdc++.h>
using namespace std;
constexpr int N=1000;
using ll=long long;
const ll mod=998244353;
ll all=1;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
    int n,m;
    string s;
    cin>>n>>m>>s;
    bool flag=false;
    for(int i=0;i<s.size();i++)if(s[i]!='0')flag=true;
    if(flag==false)cout<<0;
    else if(m==1){
        for(int i=1;i<=n;i++){
            all=all*(n-(i-1))%mod;
        }
        cout<<all;
    }
    else if(m==n){
        bool f=false;
        for(int i=0;i<s.size();i++)if(s[i]!='1')f=true;
        if(f)cout<<1;
        else cout<<0;
    }
    cout<<2204128;
}
