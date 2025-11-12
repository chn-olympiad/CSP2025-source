#include <iostream>
#include <algorithm>
#define half_int unsigned short
using namespace std;


struct Node{
	half_int l, r;
} nodes[500005];
half_int n, a[500005], k;
half_int xs[500005], psb, cnt;

bool cmp( Node x, Node y ){ return x.l < y.l; }

int main(){
	freopen( "xor.in", "r", stdin );
	freopen( "xor.out", "w", stdout );
	cin >> n >> k;
	for (int i=0; i<n; i++)
		cin >> a[i];
	xs[0] = a[0];
	for (int i=1; i<n; i++)
		xs[i] = xs[i-1] ^ a[i];
	for (half_int i=0; i<n; ++i)
		for (half_int j=i; j<n; ++j)
			if ( (xs[i-1] ^ xs[j]) == k || (i==j && a[i]==k) ){
				nodes[psb++] = (Node){i, j};
			}
	sort( nodes, nodes+psb, cmp );
	
	half_int CURR = nodes[0].r; cnt = 1;
	for ( int i=0; i<psb; i++ )
		if ( nodes[i].l > CURR )
		{ CURR = nodes[i].r; cnt++;}
	cout << cnt << endl;
	return 0;
}