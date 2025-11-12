#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
struct p{
	ll l,r;
};
bool cmp(p a, p b){
	return a.r-a.l < b.r - b.l;
}
ll n,k;
ll a[(int)5e5+5]={0};
bool f[(int)5e5+5];
//ll s[(int)5e5+5]
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	
	cin >> n >> k;
	for(ll i=1;i<=n;i++){
		cin >> a[i];
		a[i] = a[i]^a[i-1];
	}
	if(k==0){
		map<ll,ll> mp;
		for(ll i=1;i<=n;i++){
			mp[a[i]]++;
		}
		ll cnt=0;
		for(pair<ll,ll> i:mp){
			cnt += i.second*(i.second-1)/2;
		}
		cout << cnt << endl;
		return 0;
	}
	vector<p> ps;
	for(ll len = 1; len <= n; len++){
		for(ll i=1; i<=n-len+1; i++){
//			cout << "judge: a["<< i << "]:"<<a[i-1]<<" ^ a[" << i+len-1 << "]:" <<a[i+len-1] << " (=" << (a[i-1]^a[i+len-1]) << ") == " << k <<endl;
			if((a[i-1]^a[i+len-1]) == k){
//				cout << "Push!" << endl;
				ps.push_back({i,i+len-1});
			}
		}
	}
	sort(ps.begin(), ps.end(), cmp);
//	cout << "ps.size() == " << ps.size() << endl;
//	for(p t:ps){
//		cout << t.l << " " << t.r << endl;
//	}
	ll cnt=0;
	for(p t:ps){
		bool flag=0;
		for(int i=t.l;i<=t.r; i++){
			if(f[i]){
				flag=1;
				break;
			}
		}
		if(!flag){
			for(ll i=t.l;i<=t.r; i++){
				f[i]=true;
			}
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
