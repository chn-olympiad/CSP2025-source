#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
using namespace std;

signed main () {

	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);

	int n,k; scanf ("%lld%lld",&n,&k);
	
	vector <int> lis(n);
	for (int i=0;i<n;i++)
		scanf ("%lld",&lis[i]);
	
	int prexor=lis[0];
	int result=0;
	for (int i=1;i<n;i++) {
		
		if (prexor==k) {
			
			result++;
			prexor=lis[i];
			
		} else prexor=(prexor xor lis[i]);
		
	} 
	
	result+=(prexor==k);
	printf ("%lld\n",result);

	return 0;
}

