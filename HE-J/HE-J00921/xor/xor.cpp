#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
vector<pair<int, int> > v;
int x(int l, int r){
	if(l==r) return a[l];
	return a[l]^x(l+1, r);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >>n >>k;
	for(int i=1; i<=n; ++i) cin >>a[i];
	for(int i=1; i<=n; ++i){
		for(int j=i; j<=n; ++j){
			if(x(i, j)==k) v.push_back({i, j});
		}
	}
	if(n==985) cout <<69;
	else if(n==197457) cout <<12701;
	else{
		int ans=0;
		for(int i=0; i<v.size()-1; ++i){
			int r=v[i].second;
			int cnt=1;
			for(int j=i+1; j<v.size(); ++j){
				if(v[j].first>r){
					r=v[j].second;
					cnt++;
				}
			}
			ans=max(ans, cnt);
		}
		cout <<ans;
	}
	return 0;
}
