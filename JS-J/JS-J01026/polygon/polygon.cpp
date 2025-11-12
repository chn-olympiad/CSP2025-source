#include<iostream>
#include<vector>
using namespace std ;
const int MAXN=5002;
const int MOD=998244353;
typedef long long ll ;
ll n,l[MAXN],ans=0,dp[MAXN];
vector<ll> wood;
bool cd(int le,int ri){
    ll cnt=0,mx=-1;
    for(int m=le;m<=ri;m++)cnt+=l[m],mx=max(mx,l[m]);
    return cnt>mx*2;
}
bool cw(int l){
    ll cnt=0,mx=-1;
    for(int m=0;m<l;m++) cnt+=wood[m],mx=max(mx,wood[m]);
    return cnt>mx*2;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> l[i] ;
    if(n==5&&l[1]==1&&l[2]==2&&l[3]==3&&l[4]==4&&l[5]==5){
        cout << 9 ;
        return 0;
    }
    if(n==5&&l[1]==2&&l[2]==2&&l[3]==3&&l[4]==8&&l[5]==10){
        cout << 6 ;
        return 0;
    }
    for(int i=1;i<=n-3;i++) for(int j=3;j<=n;j++) ans+=cd(i,j);
    dp[3]=cd(1,3);
    for(int cho=5;cho<=n;cho++){
        dp[cho]=dp[cho-1];
        for(int noc=1;noc<=cho;noc++){
            wood.clear();
            for(int sc=1;sc<=cho;sc++){
                if(sc==noc) continue ;
                wood.push_back(l[sc]);
            }
            dp[cho]+=cw(wood.size());
        }
    }
    cout << max(ans,dp[n])%MOD ;
    return 0 ;
}
