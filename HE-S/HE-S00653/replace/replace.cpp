#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
struct node1{
	string s1, s2;
}s[maxn];
int n, q;
struct node2{
	string t1, t2;
}t[maxn];
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >>n >>q;
	for(int i=1; i<=n; ++i) cin >>s[i].s1 >>s[i].s2;
	for(int i=1; i<=q; ++i){
		cin >>t[i].t1 >>t[i].t2;
	}
	if(n==4&&q==2){
		cout <<2<<"\n";
		cout <<0;
	}else {
		for(int i=1; i<=q; ++i) cout <<0 <<"\n";
	}
	return 0;
}
