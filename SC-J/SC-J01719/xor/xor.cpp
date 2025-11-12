#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int n,k;
int a[N];
int xor_pre[N];

struct Range {
	int st;
	int ed;
	int last;
	
	bool operator<(const Range& other) const {
		return this->ed < other.ed;
	}
	
	int compareTo(const Range& other) {
		if(this->ed < other.st) return 1;
		return -1;
	}
	
	// Override
	string to_string() {
		return "{\"st\": \""+std::to_string(this->st)+"\",\"ed\": "+std::to_string(this->ed)+"\",\"range\": "+std::to_string(this->last)+"\"}";
	}
};

Range make_range(int st,int ed) {
	Range r;
	r.st = st;
	r.ed = ed;
	r.last = ed-st;
	return r;
}

vector<Range> rec;

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	xor_pre[0] = 0; // 1^0 = 1 & 0^0 = 0
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if (i==1) {xor_pre[i] = a[i];}
		else {xor_pre[i] = xor_pre[i-1] ^ a[i];}
		if(a[i] == k) rec.push_back(make_range(i,i));
		
		// a^b^b == a
	}
//	for(int i=1;i<=n;i++) {cout<<xor_pre[i]<<" ";}
//	cout<<"\n";
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;++j) {
			if((xor_pre[i] ^ xor_pre[j-1]) == k) rec.push_back(make_range(j,i));
		}
	}
	
	// 
	sort(rec.begin(),rec.end());
//	for(auto x:rec) cout<<x.to_string()<<"\n";
	
	long long ans=1;
	if(rec.size() < 1) {cout<<0<<"\n";return 0;}
	Range tmp = rec[0];
	for(int i=1;i<(int)rec.size();++i) {
		if(tmp.compareTo(rec[i]) == 1) {
			++ans;
			tmp = rec[i];
		}
	}
	
	cout<<ans<<"\n";
	return 0;
}