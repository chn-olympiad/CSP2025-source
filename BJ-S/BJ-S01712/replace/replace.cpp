#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const ll q=311;
const ll MOD=998244353;
ll qtimes[5000005],hashinx[200005],hashiny[200005],len1[200005],hashx[5000005],hashy;
ll n,q1;
string in[200005][2],x,y;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q1;
    qtimes[0]=1;
    for(int i=1;i<=5000000;i++){
        qtimes[i]=(qtimes[i-1]*q)%MOD;
    }
    for(int i=1;i<=n;i++){
        cin>>in[i][0]>>in[i][1];
        len1[i]=in[i][0].size();
        in[i][0]=' '+in[i][0];
        in[i][1]=' '+in[i][1];
        hashinx[i]=0;
        hashiny[i]=0;
        for(int j=1;j<=len1[i];j++){
            hashinx[i]=(hashinx[i]*q+in[i][0][j])%MOD;
            hashiny[i]=(hashiny[i]*q+in[i][1][j])%MOD;
        }
    }
    while(q1--){
        cin>>x>>y;
        ll xlen=x.size();
        if(xlen!=y.size()){
            continue;
        }
        x=' '+x;
        y=' '+y;
        hashx[0]=0;
        hashy=0;
        for(ll i=1;i<=xlen;i++){
            hashx[i]=(hashx[i-1]*q+x[i])%MOD;
            hashy=(hashy*q+y[i])%MOD;
        }
        ll ans114514=0;
        for(ll i=1;i<=n;i++){
            ll t=0;
            for(ll j=1;j+len1[i]-1<=xlen;j++){
                ll chk=0;
                chk=hashx[j+len1[i]-1]-hashx[j-1]*qtimes[len1[i]];
                chk%=MOD;
                chk+=MOD;
                chk%=MOD;
                if(chk!=hashinx[i]){
                    continue;
                }
                ll newans=0;
                newans=hashx[j-1]*qtimes[xlen-j+1]+
                hashiny[i]*qtimes[xlen-j-len1[i]+1]+
                (hashx[xlen]-hashx[j+len1[i]-1]*qtimes[xlen-j-len1[i]+1]);
                newans%=MOD;
                newans+=MOD;
                newans%=MOD;
                if(newans==hashy){
                    t=1;
                    break;
                }
            }
            if(t==1){
                ans114514++;
            }
        }
        cout<<ans114514<<endl;
    }
    return 0;
}
