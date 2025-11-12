#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e4+10;

ll n, h, l, a[N], a1, b1;

bool cmp(ll a2, ll b2){return a2>b2;}

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> a1 >> b1;
    n = a1*b1;
    for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
    ll num = a[1];
    sort(a+1,a+n+1,cmp);
    for (int i = 1; i <= n; i++){
        if (a[i]==num) num = i;
    }
    l = num/a1+((num%a1)>0);
    if (l%2){
        h = num%a1;
        if (h==0) h = a1;
    }
    else{
        h = num%a1;
        if (h==0) h = a1;
        h = a1-h+1;
    }
    cout << l << " " << h;
    return 0;
}
