#include <bits/stdc++.h>
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
using namespace std;

signed main () {

	freopen ("employ.in","r",stdin);
	freopen ("employ.out","w",stdout);
	
	int n,m; scanf ("%lld%lld",&n,&m);
	string s; cin>>s;
	
	vector <int> c (n),arr;
	for (int i=0;i<n;i++) {
		
		scanf ("%lld",&c[i]);
		arr.push_back (i);
		
	}
	
	int result=0;
	
	int checkA=0;
	for (int i=0;i<s.size ();i++)
		checkA+=(s[i]=='1');
	
	do {
		
		int pre=0,cnt=0;
		for (int i=0;i<n;i++) {
			
			if (pre>=c[arr[i]]) {
				
				pre++;
				continue ;
				
			}
			
			if (s[i]=='1') cnt++;
			else pre++;
			
		}
		
		if (cnt>=m) result=(result+1)%mod;
		
	} while (next_permutation (arr.begin (),arr.end ()));
	
	printf ("%lld\n",result);

	return 0;
}

