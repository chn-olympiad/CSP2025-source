#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int tt[550];
int hd[550];
const int M=998244353;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>tt[i];
    int su=0;
    for(int i=1;i<=n;i++) hd[i]=s[i-1]-'0',su+=hd[i];
    if(su==n){
        for(int i=1;i<=n;i++) if(!tt[i]) su--;
        ll t=1;
        for(int i=1;i<=su;i++) t=(t*i)%M;
        cout<<t;
        return 0;
    }
    return 0;
}