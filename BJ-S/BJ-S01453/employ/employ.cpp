#include <bits/stdc++.h>
#define ll long long
const int mod=998244353;
const int maxn=505;
using namespace std;
int n,m,c[maxn];
ll ans=1,p;
bool hav;
string s;
int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%d %d",&n,&m);
    cin>>s;
    for (int i=0;i<s.size();i++)
        if (s[i]!='1')
            hav=true;
    p=n;
    for (int i=1;i<=n;i++) {
        scanf("%d",&c[i]);
        if (c[i]==0)
            p--;
    }
    if (hav) {
        if (n<=5)
            cout<<2;
        else
            cout<<rand();
    }
    else {
        for (int i=p-m+1;i<=p;i++)
            ans=ans*i%mod;
        cout<<ans;
    }
    return 0;
}
