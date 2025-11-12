#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define debug(nm,val) cout<<"Debug :"<<nm<<' '<<val<<'\n'
#define ull unsigned long long
#define p 131
using namespace std;
															
signed main () {

	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
    
	int n,q; scanf ("%lld%lld",&n,&q);
	const int N=5e6;
	vector <ull> pw(N+7);
	pw[0]=1;
	for (int i=1;i<=N;i++)
		pw[i]=pw[i-1]*p;
	
	map <ull,map <ull,bool> > had;
	for (int i=0;i<n;i++) {
		
		string a,b; cin>>a>>b;
		ull Ha=0,Hb=0;
		for (int j=0;j<a.size ();j++) {
			
			Ha=Ha*p+(a[j]-'a'+1);
			Hb=Hb*p+(b[j]-'a'+1);
			
		} had[Ha][Hb]=true;
		had[Hb][Ha]=true;
		
	}

	while (q--) {
		
		string a,b; cin>>a>>b;
		
		int lena=a.length (),lenb=b.length ();
		
		if (lena!=lenb) {
			
			printf ("0\n");
			continue ;
			
		}
		
		vector <ull> Ha (lena,0),Hb (lena,0);
		for (int i=0;i<lena;i++)
			Ha[i]=Ha[max (i-1,0ll)]*p+(a[i]-'a'+1);
		for (int i=0;i<lena;i++)
			Hb[i]=Hb[max (i-1,0ll)]*p+(b[i]-'a'+1);
			
		auto geta=[&] (int l,int r) {
			return Ha[r]-(l==0 ? 0 : Ha[l-1])*pw[r-l+1]; 
		};
		auto getb=[&] (int l,int r) {
			return Hb[r]-(l==0 ? 0 : Hb[l-1])*pw[r-l+1];
		};
		
		auto ask=[&] (int l,int r) {
			return geta (l,r)==getb (l,r);
		};
		int result=0;
		for (int l=0;l<lena;l++) {
			for (int r=0;r<lena;r++)
				if (!ask (l,r))
					if (had[geta (l,r)][getb (l,r)]) {
						ull newA=geta(0,max (l-1,0ll))*pw[lena-l-1]+geta (l,r)*pw[lena-r-1]+geta (min (r+1,lena-1),lena-1);
						if (newA==Hb[lena-1]) result++;
					}
			
		}			
		
		printf ("%lld\n",result);
	} 
	                                                                                       
	
	return 0;
}

/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
