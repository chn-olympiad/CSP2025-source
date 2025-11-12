#include <bits/stdc++.h>
using namespace std;

long long n,m,p,x,yu,sh;
long long a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (long long i=1;i<=n*m;i++)
        cin >> a[i];
    p=a[1];
    sort(a+1,a+n*m+1);
    x=lower_bound(a+1,a+n*m+1,p)-a;
    x=n*m-x+1;
    yu=(x-1)%n+1;
    sh=(x-1)/n+1;
    if(sh%2==0)
        yu=n-yu+1;
    cout << sh << ' ' << yu << "\n";
    return 0;
}