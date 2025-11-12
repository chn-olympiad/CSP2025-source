#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],c[505],sum1,sum2,sum0;
long long ans;
string s;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin >> n >> m;
    cin >> s;
    bool f=1;
    for (int i=1;i<=n;i++){
        cin >> c[i];
        if (c[i]==0) sum0++;
        sum1+=c[i];
    }
    for (int i=0;i<s.size();i++){
        a[i+1]=a[i]+((s[i]-'0')^1);
        if (s[i]-'0'==0) f=0;
        sum2+=a[i+1];
    }
    if (f){
        ans=1;
        if (n-sum0>=m){
            for (int i=1;i<=n;i++) ans=(ans*i)%998244353;
        }
        else if(n-sum0+1>=m){
            ans=sum0;
            for (int i=1;i<=n-1;i++) ans=(ans*i)%998244353;
        }
        else{
            cout << 0;
            return 0;
        }
        cout << ans;
        return 0;
    }
    else if (sum1<=sum2+m||m>n-a[n]||m>18) cout << 0;
    return 0;
}
