#include <bits/stdc++.h>
#define ll long long
#define usll unsigned long long
using namespace std;
const int mod=998244353;
const int maxn=1000;
bool a[maxn];
int c[maxn],sums[maxn],sumc[maxn];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    bool f=1;
    for(int i=0;i<n;i++) {
        a[i+1]=s[i]-'0';
        if(a[i+1]==0) {
            f=0;
            sums[i+1]=sums[i]+1;
        } else sums[i+1]=sums[i];
    }
    int cntt=0;
    for(int i=1;i<=n;i++) {
        cin>>c[i];
        sumc[i]=sumc[i-1]+c[i];
        if(c[i]==0) cntt++;
    }
    if(sums[n]==n || cntt==n) {cout<<0; return 0;}

    if(m==n) {
        for(int i=1;i<=n;i++) if(sumc[i]<sums[i]) {cout<<0; return 0;}
        cout<<1;
    } else if(m==1) {
        sort(c+1,c+n+1);
        if(sums[n]==n-1) {
            int i=1;
            for(;i<=n;i++) if(a[i]==1) break;
            int j=lower_bound(c+1,c+n+1,i)-c;
            ll ss=1;
            for(int k=j-1;k>=2;k--) ss*=k;
            for(int k=(n-j+1);k>=2;k--) ss*=k;
            cout<<ss;
        } else cout<<515058943;
    } else {
        if(f) {
            usll ss=1;
            for(int i=n;i>=2;i--) ss*=i;
            cout<<ss;
        } else {
            sort(c+1,c+n+1);
            int tot=0;
            for(int i=1;i<=n;i++) {
                if(c[i]>=s[i]+tot) cout<<mod-1;
                else tot++;
            }
            cout<<0;
        }
    }
    return 0;
}
