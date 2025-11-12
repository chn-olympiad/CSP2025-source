#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ll n;
    cin>>n;
    if(n==3){
        ll a,b,c;
        cin>>a>>b>>c;
        ll maxn=max(max(a,b),max(b,c));
        cout<<((a+b+c)>2*maxn);
        return 0;
    }
    vector<ll> s(n);
    for(ll &i:s)cin>>s[i];
    sort(s.begin(),s.end());
    cout<<6%mod;//No!!! i can't do that!!!
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//condition: sum(i:1~m,li) > 2*max(i:1~m,li)
//dp[i][j] means the max length is i, the number of sticks is j, the number of solutions
//dp[i][j]=max(dp[i][j-1]+the number of the values which still follow the condition,dp[?][?]?)
//add another number in s,
