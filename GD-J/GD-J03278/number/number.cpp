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
string s;
int a[15];
bool flag;
start_code
openfile(number);
cin>>s;
for (auto i:s) if (i>='0' && i<='9') a[i-'0'] ++;
for (int i = 9;i >= 1;i --)
	while (a[i] --)
		cout<<i,flag = true;
if (flag) while (a[0] --) cout<<0;
else cout<<0;
stop_code
