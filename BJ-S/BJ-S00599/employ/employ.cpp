#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1,P=998244353;
LL n,m,s,x,ans=1;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)   cin>>x;
    for(int i=1;i<=n;i++){
        ans=(ans*i)%P;
    }
    cout<<ans;
    return 0;
}
//Ren5Jie4Di4Ling5%
