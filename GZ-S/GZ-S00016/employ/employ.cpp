//GZ-S00016 中央民族大学附属中学贵阳学校 伍兴睿麟
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int n,m;
ll ans=1;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    cin>>s;
    for(int x,i=1;i<=n;i++){
        cin>>x;
    }
    for(int i=1;i<=n;i++){
        ans=ans*i%998244353;
    }
    cout<<ans<<endl;
    return 0;
}
