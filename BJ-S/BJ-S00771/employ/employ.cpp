#include<bits/stdc++.h>
using namespace std;
const int N=20;
const int mod=998244353;
int n,m,cnt,ans;
string s;
int c[N];
int main(){
    //freopen("employ.in","r",stdin);
    //freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    cin>>s;
    s=" "+s;
    for(int i=1;i<=n;++i) cin>>c[i];
    do{
        cnt=0;
        for(int i=1;i<=n;++i){
            //cout<<c[i]<<" ";
            if(cnt>=c[i]){
                ++cnt;
                continue;
            }
            if(s[i]=='0'){
                ++cnt;
            }
        }
        if(n-cnt>=m) ans++;
        ans%=mod;
    }while(next_permutation(c+1,c+n+1));
    cout<<ans;
    return 0;
}
