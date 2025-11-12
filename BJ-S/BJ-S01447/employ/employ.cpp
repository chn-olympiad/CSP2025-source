#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#define endl '\n'
using namespace std;
using ll=long long;
const int mod=998244353;
int n,m,c[505],p[505];
ll ans;
bool s[505];
int main(){
    freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        char t; cin>>t;
        s[i]=(t=='1'),p[i]=i;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    do{
        int sumc=0,summ=0;
        for(int i=1;i<=n;i++)
            if(sumc<c[p[i]] and s[i]){
                summ++;
                if(summ>=m){ans=(ans+1)%mod; break;}
            }else sumc++;
    }while(next_permutation(p+1,p+n+1));
    cout<<ans<<endl;
    return 0;
}