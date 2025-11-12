#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node1{
	string s1,s2;
}a1[N];
struct node2{
	string s1,s2;
}a2[N];
int n,q;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 1; i <= n; i++) cin >> a1[i].s1 >> a1[i].s2;
	for(int j = 1; j <= q; j++) cin >> a2[i].s1 >> a2[i].s2;
	return 0;
} 
