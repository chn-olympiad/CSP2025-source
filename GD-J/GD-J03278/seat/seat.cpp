#include <bits/stdc++.h>
#define start_code signed main(){
#define stop_code return 0;}
#define elif else if
#define infile(x) freopen(#x".in","r",stdin)
#define outfile(x) freopen(#x".out","w",stdout)
#define ansfile(x) freopen(#x".ans","w",stdout)
#define openfile(x) (infile(x),outfile(x))
#define fastio() (ios::sync_with_stdio(0),cin.tie(0),cout.tie(0))
#define powi2(x) ((x)*(x))
#define pow2i(x) (1<<(x))
//#define int long long
using namespace std;
int n,m,a[105],x,p,c,r;
start_code
openfile(seat);
cin>>n>>m;
for (int i = 1;i <= n*m;i ++) cin>>a[i];
x = a[1],sort(a+1,a+n*m+1,greater<int>());
for (int i = 1;i <= n*m;i ++) if (a[i] == x) {p = i; break ;}
c = (p-1)/n+1;
if (c & 1) r = (p-(c-1)*n);
else r = n-(p-(c-1)*n)+1;
cout<<c<<' '<<r;
stop_code
