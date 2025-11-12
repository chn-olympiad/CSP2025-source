#include<bits/stdc++.h>
using namespace std;

int const N = 1E5 + 5;
int t, n, a[N], b[N], c[N], ac[N], bc[N];

struct Node {
	int a, b, c, ac, bc, ab;
}node[N];

bool cmpa(Node a, Node b) {
	return a.ab > b.ab;
}

bool cmpb(Node a, Node b) {
	return a.bc > b.bc;
}

bool cmpc(Node a, Node b) {
	return a.ac > b.ac;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		memset(c, 0, sizeof(c));
		int tl = 0;
		for(int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			node[i].a = a;
			tl += a;
			node[i].b = b;
			node[i].c = c;
			node[i].ab = b - a;
			node[i].ac = c - a;
			node[i].bc = c - b;
		}
		
		sort(node + 1, node + 1 + n, cmpa);
		for(int i = 1; i <= n / 2; i++) {
			tl += node[i].ab; 
//			cout << node[i].ab << " ";
		}
//		cout << endl;
		
		sort(node + 1, node + n / 2 + 1, cmpb);
		
		b[0] = tl;
		for(int i = 1; i <= n / 2; i++) {
			int r = node[i].bc;
			if(r < 0) {
				b[i] = tl;
				continue;
			}
			tl += r;
			b[i] = tl;
//			cout << b[i] << endl;
		}
		
		sort(node + 1 + n / 2, node + 1 + n, cmpc);
		int r = 0;
		for(int i = 1 + n / 2; i <= n; i++) {
			r += node[i].ac;
			if(r < 0) break;
			
			tl = max(tl, b[n / 2 - i] + r);
//			cout << b[n / 2 - i] << endl;
		}
		
		cout << tl << endl;
	}
	return 0;
}

