#include<bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
const int N=1e5+9;
int a[N];
pair<int,int> b[N];
int vb,vc,va;
int n,m,ans=1;
string s;
signed main(){
   freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    //next_permutation()
  cin>>n>>m;
  string s;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    vc=max(vc,a[i]);
  }
  if(n==1){
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')
        {
             if(i>vc) cout<<0;
             return 0;
        }

    }
    for(int i=n-1;i>=1;i--){
        (ans*=i)%=mod;
    }
    cout<<ans<<endl;
    return 0;
  }
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')
        {
             cout<<0<<endl;
            return 0;
        }

    }
    for(int i=n;i>=1;i--){
        (ans*=i)%=mod;
    }
    cout<<ans<<endl;
return 0;
}

