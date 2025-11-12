
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int P=998244353;
typedef long long ll;
ll ans=1,cnt;
int a[114];

int main(){
    freopen("employ.in","r",stdin);
   freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0) cnt++;
    }
    if(n-cnt<m)
    {
        cout<<0;
        return 0;
    }
        for(int i=1;i<=n-cnt;i++)
        {
            ans=(1ll*ans*i)%P;
        }
        cout<<ans%P;
        return 0;

    return 0;
}
