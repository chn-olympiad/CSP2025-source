#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
using namespace std;

struct node {
	int a,b,c;
};

int n;
vector <node> arr;
int result;


void dfs (int step,int Acnt,int Bcnt,int Ccnt,int tot) {
	
	if (step>=n) {
		
		result=max (result,tot);
		return ;
		
	}
	
	if (Acnt+1<=n/2) dfs (step+1,Acnt+1,Bcnt,Ccnt,tot+arr[step].a);
	if (Bcnt+1<=n/2) dfs (step+1,Acnt,Bcnt+1,Ccnt,tot+arr[step].b);
	if (Ccnt+1<=n/2) dfs (step+1,Acnt,Bcnt,Ccnt+1,tot+arr[step].c);
	
}

void solve () {
	
	scanf ("%lld",&n);
	
	int check2=0,check3=0;
	
	arr.resize (n);
	vector <int> A;
	for (int i=0;i<n;i++) {
		
		scanf ("%lld%lld%lld",&arr[i].a,&arr[i].b,&arr[i].c);
		check2+=(arr[i].b==0);
		check3+=(arr[i].c==0);
		A.push_back (arr[i].a);
		
	}
	
	if (check2==n && check3==n) {
		
		result=0;
		
		sort (A.rbegin (),A.rend ());
		for (int i=0;i<n/2;i++) result+=A[i];
		
		printf ("%lld\n",result);
		
		return ;
		
	}
	
	result=-inf;
	dfs (0,0,0,0,0);
	
	printf ("%lld\n",result);
		
}

signed main () {

	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	
	int T; scanf ("%lld",&T);
	
	while (T--)
		solve ();

	return 0;
}


