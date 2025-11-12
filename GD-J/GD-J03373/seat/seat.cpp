#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
using namespace std;

signed main () {

	freopen ("seat.in","r",stdin);
	freopen ("seat.out","w",stdout);

	int n,m; scanf ("%lld%lld",&n,&m);
	
	vector <int> score(n*m);
	for (int i=0;i<n*m;i++)
		scanf ("%lld",&score[i]);
		
	int Rscore=score[0];
	
	
	sort (score.rbegin (),score.rend ());
	
	int Ridx;
	for (int i=0;i<n*m;i++)
		if (score[i]==Rscore) {
			
			Ridx=i+1;
			break;
			
		}
		
	int c=(Ridx/n)+(Ridx%n==0 ? 0 : 1);
	int r;
	if (c%2) r=(Ridx%n==0 ? n : Ridx%n);
	else r=(Ridx%n==0 ? 1 : (n-Ridx%n+1));
	
	printf ("%lld %lld\n",c,r);

	return 0;
}

