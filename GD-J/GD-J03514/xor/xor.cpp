#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int le, ri;
struct node {
	int l, r;
} a[N*N], b[N*N];
vector < int > st[N*N];
vector < int > ed[N*N];
int t;
int tmp;
int cnt;
int arr[N*N];
int n, k;
int f[N][N]; 

bool comp (node x, node y) {
	return x.l < y.l;
}

int main () {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		f[i][i] = arr[i];
		
		if (f[i][i] == k) {
			a[ ++t ] = { i , i };
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = f[i][j - 1] ^ arr[j];
			if (f[i][j] == k) {
				t++;
				a[t].l = i;
				a[t].r = j;
			}
		}
	}
	
	for (int i = 1; i <= t; i++) {
		st[ a[ i ].l ].push_back(i);
		ed[ a[ i ].r ].push_back(i);
	}
	
	sort(a+1, a+t+1, comp);
	
	for (int i = 1; i <= t; i++) {
		
		int pos;
		int minn = 2e9;
		
		for (int j = 0; j < st[ i ].size(); j++) {
			int x = st[ i ][ j ];
			
			if ( a[ x ].r - a[ x ].l + 1 < minn ) {
				minn = a[ x ].r - a[ x ].l + 1;
				
				pos = x;
			}
		}
		
		tmp++;
		b[ tmp ] = a[ pos ];
		
		minn = 2e9;
		
		for (int j = 0; j < ed[ i ].size(); j++) {
			int x = ed[ i ][ j ];
			
			if ( a[ x ].r - a[ x ].l + 1 < minn ) {
				minn = a[ x ].r - a[ x ].l + 1;
				
				pos = x;
			}
		}
		tmp++;
		b[ tmp ] = a[ pos ];
		
	}
	sort( b + 1 , b + tmp + 1 , comp );
	
	for (int i = 1; i <= tmp; i++) {
		if ( a[i].l > ri ) {
			ri = a[i].r;
			
			cnt++;
		}
	}
	
	cout << cnt;
	return 0; 
} 
