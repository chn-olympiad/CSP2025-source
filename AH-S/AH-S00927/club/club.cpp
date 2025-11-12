#include<bits/stdc++.h>
using namespace std;
int t , n , ff[100005] , ss[100005] , tt[100005] , nf[100005] , ns[100005] , nt[100005] , s , w;
bool cmp (int x , int y) {
	return x>y;
}
int main () {
	freopen ("club.in" , "r" , stdin);
	freopen ("club.out" , "w" , stdout);
	cin >> t;
	while (t--) {
		cin >> n;
		w=n/2;
		s=0;
		for (int i=1 ; i<=n ; i++) {
			cin >> nf[i] >> ns[i] >> nt[i];
			if (nf[i]<ns[i]) {
				swap (nf[i] , ns[i]);
			}
			ff[i]=nf[i];
			ss[i]=ns[i];
			tt[i]=nt[i];
		}
		if (ns[1]==0) {
			sort (ff+1 , ff+1+n , cmp);
			for (int i=1 ; i<=w ; i++) {
				s+=ff[i];
			}
			cout << s << endl;
		} else {
			sort (ff+1 , ff+1+n , cmp);
			for (int i=1 ; i<=w ; i++) {
				s+=ff[i];
				for (int j=1 ; j<=n ; j++) {
					if (nf[j]==ff[i]) {
						nf[j]=ns[j]=0;
					}
				}
			}
			for (int i=1 ; i<=n ; i++) {
				if (ff[i]<ss[i]) {
					swap (nf[i] , ns[i]);
				}
			}
			for (int i=1 ; i<=n ; i++) {
				ff[i]=nf[i];
				ss[i]=ns[i];
				tt[i]=nt[i];
			}
			sort (ss+1 , ss+1+n , cmp);
			for (int i=1 ; i<=w ; i++) {
				s+=ss[i];
				ss[i]=ff[i]=0;
			}
			cout << s << endl;
		}
	}
	return 0;
}
