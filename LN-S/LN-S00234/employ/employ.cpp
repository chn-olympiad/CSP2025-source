#include<bits/stdc++.h>
#define EQ ==
using namespace std;
typedef long long ll;
const int N=555;
const int mod=998244353;
int n,m,c[N],num[N];
string S;
int main(){
    cin.tie(0)->ios::sync_with_stdio(0);
    cout.tie(0)->ios::sync_with_stdio(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m>>S;S=' '+S;
    for(int t=1;t<=n;t++){
        cin>>c[t];num[c[t]]++;
    }
    if(m EQ n){
        bool opt1=1;ll ans=1;
        for(int t=1;t<=n;t++){
            opt1&=(S[t] EQ '0');
            opt1&=(c[t]>0);ans=ans*t%mod;
        }
        cout<<(opt1 ? ans : 0)<<'\n';
        return 0;
    }

    return 0;
}