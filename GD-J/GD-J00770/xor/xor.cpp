#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;
int a[maxn], ans[maxn], cnt[maxn];
long long n;
int r[maxn], R[maxn];
int cfsl[maxn], sl;
struct N {
	int l, r;
	bool fl;
};
int ANS;

int main () {
	freopen( "xor.in" ,"r" ,stdin );
	freopen( "xro.out" ,"w" ,stdout );
	int f, k;
	cin >> f >> k; 
	for ( int i=1;i<=f;i++ ) {
		cin >> a[i];
		if ( i==1 ) ans[i] = a[i]; 	
		else ans[i] = ans[i-1]^a[i];
		
	}
	for ( int i=1;i<=f;i++ ) {
		for ( int j=1;j<=f;j++ ) {
			if ( ans[j]^ans[j-i]==k ) {
				sl++;
				r[j]++;
			}
		}   
	}
	int g=0;
	for ( int i=1; i<=f;i++ ) {
		g += r[i];
		R[i] = g;
	}
	for ( int i=1;i<=sl;i++ ) {
		if ( cfsl[i] == 0 ) {
			ANS++;
			cnt[i] = 0;
		}
	}	
	sort ( cfsl + 1, cfsl + sl + 1);
	int jsp;
	for ( int i=1;i<=sl;i++ ) {
		if ( cnt[i] == 0 ) continue;
		if ( jsp == 0 ) {
			ANS++;
			jsp += cfsl[i] + 1;
		} 
		jsp++;
	}
	cout << ANS;	
	return 0;
}
