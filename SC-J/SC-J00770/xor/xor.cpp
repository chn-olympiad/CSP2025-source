#include<iostream>
using namespace std;
const int N = 5e5+5;

int n,k,a[N],start_max[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
		a[i] ^= a[i-1];
	}
	for(int i=1;i<=n;++i) start_max[i] = -1;
	for(int len=1;len<=n;++len) {
		for(int l=1,r=l+len-1;r<=n;++l,++r) {
			if((a[r]^a[l-1])==k) {
				if(start_max[r]<l) start_max[r] = l;
			}
		}
	}
	int lst=0,ans=0;
	for(int r=1;r<=n;++r) {
		if(start_max[r]>lst) {
			lst = r;
			++ans;
		}
	}
	cout<<ans;
	return 0;
}