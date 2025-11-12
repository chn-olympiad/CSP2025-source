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
const int N = 505,MOD = 998244353;
int n,m,c[N],ans,sum[N],flag = 1;
string s;
start_code
openfile(employ);
cin>>n>>m>>s;s = " "+s;
for (int i = 1;i <= n;i ++) cin>>c[i];
for (int i = 1;i <= n;i ++) if (s[i] == '0') {flag = 0;break;}
/*if (flag)
{
	
}*/
int indx[N],d[N];
for (int i = 1;i <= n;i ++) indx[i] = i;
do {
	int cnt = 0,fa = 0;
	for (int i = 1;i <= n;i ++) d[indx[i]] = c[i];
	//for (int i = 1;i <= n;i ++) cout<<d[i]<<' ';
	for (int i = 1;i <= n;i ++)
	{
		if (s[i] == '0') {fa ++;continue ;}
		if (fa >= d[i]) {fa ++;continue ;}
		cnt ++;
	}
	if (cnt >= m) (++ ans) %= MOD;
	//cout<<'\n';
} while (next_permutation(indx+1,indx+n+1));
cout<<ans;
stop_code
