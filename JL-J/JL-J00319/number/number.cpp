#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6+10;

string s;
ll tot, a[N], n;

bool cmp(ll a1, ll b1){return a1>b1;}

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++){
        if (s[i]>='0'&&s[i]<='9') a[++tot] = s[i]-'0';
    }
    sort(a+1,a+tot+1,cmp);
    for (int i = 1; i <= tot; i++) printf("%lld",a[i]);
    return 0;
}
