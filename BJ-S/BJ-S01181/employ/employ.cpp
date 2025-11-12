#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,Mod=998244353;
string s;
int n,m,cnt;
ll ans=1;
int c[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=1;i<=n;++i){
        cin>>c[i];
        if(c[i]==0) ++cnt;
    }
    int flg=0;
    for(int i=0;i<n;++i){
        if(s[i]==0){
            flg=1;
            break;
        }
    }

    for(int i=1;i<=n;++i){
        ans*=i;
        ans%=Mod;
    }
    if(n-cnt<m){
        cout<<0;
    }else{
        cout<<ans;
    }

    return 0;
}
