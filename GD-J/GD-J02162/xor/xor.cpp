#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, k, a[500005], sum[500005];
vector<pair<int, int> > vc;
bool cmp(pair<int, int> x, pair<int, int> y){
	if(x.second!=y.second){
		return x.second<y.second;
	}
	return x.first<y.first;
}
signed main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum[i]=sum[i-1]^a[i];
		if(sum[i]==k){
			vc.push_back({1, i});
		}
		for(int j=1;j<i;j++){
			if((sum[i]^sum[j])==k){
				vc.push_back({j+1, i});
			}
		}
	}
	if(vc.size()==0){
		cout << 0 << endl;
		return 0;
	}
	sort(vc.begin(), vc.end(), cmp);
	int r=vc[0].second, ans=1;
	for(int i=1;i<vc.size();i++){
		if(vc[i].first>r){
			r=vc[i].second;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
