#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500001];
long t;
long long ans;
long long tor;
struct ar{
	long long l,r;
}area[10000001];
long long r;
bool amp(ar a,ar b){
	if (a.r==b.r) return a.l<b.l;
	return a.r<b.r;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) {
		if (a[i]==k) {
			tor++;
			area[tor].l=i;
			area[tor].r=area[tor].l;
			continue;
		}
		if (a[i]==0) {
			if (k==0) {
			    tor++;
				area[tor].l=i;
				area[tor].r=area[tor].l;
			}
			continue;
		}
		t=a[i];
		for (int j=i+1;j<=n;j++) {
			t=(t^a[j]);
			if (t==k) {
				tor++;
				area[tor].l=i;
				area[tor].r=j;
			}
		}
	}
	sort(area+1,area+tor+1,amp);
    r=area[1].r;
	ans=1;
	for (int i=2;i<=tor;i++) {
		if (area[i].l>r) {
			ans++;
			r=area[i].r;
		}
	}
	cout<<ans;
	return 0;
}