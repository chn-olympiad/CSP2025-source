#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int B = (1 << 20) + 2;
int n,k;
int a[N];
int xo[N];
int ind[B];
struct node{
	int l,r;
};
vector<node> v;
bool cmp(node a,node b){
	if(a.r == b.r){
		return a.l < b.l;
	}
	return a.r < b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin >> n >> k;
	xo[0] = 0;
	memset(ind,-1,sizeof(ind));
	ind[0] = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		xo[i] = (xo[i - 1] ^ a[i]);
		if(ind[k ^ xo[i]] != -1){
			v.push_back({ind[k^xo[i]] + 1,i});//[i,j]
		}
		ind[xo[i]] = i;
	}
	sort(v.begin(),v.end(),cmp);
//	for(int i = 0;i < v.size();i++){
//		cout << v[i].l << ' ' << v[i].r << endl;
//	}

	int al = 0,ar = 0,cnt = 0;
	for(int i = 0;i < v.size();i++){
		if(ar < v[i].l){
			ar = v[i].r;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
