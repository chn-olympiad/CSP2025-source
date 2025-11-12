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
const int N = 2e5+5;
int T,n,ans,a[N][3],l[3],m[N][3];
multiset<int> s[3];
start_code
openfile(club);
fastio();
cin>>T;
while (T --)
{
	cin>>n,ans = l[0] = l[1] = l[2] = 0,s[0].clear(),s[1].clear(),s[2].clear();
	for (int i = 1;i <= n;i ++)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if (a[i][0] > max(a[i][1],a[i][2])) m[i][1] = 0;
		elif (a[i][1] > max(a[i][0],a[i][2])) m[i][1] = 1;
		else m[i][1] = 2;
		if (a[i][0]>min(a[i][1],a[i][2]) && a[i][0]<max(a[i][1],a[i][2])) m[i][2] = 0;
		elif (a[i][1]>min(a[i][0],a[i][2]) && a[i][1]<max(a[i][0],a[i][2])) m[i][2] = 1;
		else m[i][2] = 2;
		l[m[i][1]] ++,s[m[i][1]].insert(a[i][m[i][1]]-a[i][m[i][2]]);
		ans += max({a[i][0],a[i][1],a[i][2]});
	}
	//cout<<ans<<'\n';
	for (int i = 0;i < 3;i ++)
		while (l[i] > n/2)
			l[i] --,ans -= *s[i].begin()
			//,cout<<i<<' '<<*s[i].begin()<<"ha\n"
			,s[i].erase(s[i].begin());
	cout<<ans<<'\n';
}
stop_code 
