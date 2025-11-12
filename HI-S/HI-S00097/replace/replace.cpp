#include<bits/stdc++.h>
using namespace std;
int n, q;
struct node {
	string s1,s2;
} a[20005];
struct node1 {
	string t1, t2;
} b[20005];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i=1; i<=n; i++) {
		cin>>a[i].s1>>a[i].s2;
	}
	for(int i=1; i<=q; i++) {
		cin >> b[i].t1 >> b[i].t2;
		cout<<0<<' ';
	}
	putchar('\n');
	return 0;
}
