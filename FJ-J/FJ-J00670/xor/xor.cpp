#include <iostream>
#include <algorithm>
using namespace std;

int My_xor(int x,int y) {
	if(x==0) return y;
	if(y==0) return x;
	return ((x|y)-(x&y));
}

int f[1005][1005];
pair<int,int> a[100005];

int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int x=0;
	for(int i=1; i<=n; i++) {
		cin>>f[i][i];
		if(f[i][i]==k) {
			a[++x].first=i;
			a[x].second=i;
		}
	}
	for(int len=2; len<=n; len++) {
		for(int i=1; i+len-1<=n; i++) {
			f[i][i+len-1]=My_xor(f[i][(i+len-1)/2],f[(i+len-1)/2+1][i+len-1]);
			if(f[i][i+len-1]==k) {
				a[++x].first=i;
				a[x].second=i;
			}
		}
	}
	sort(a+1,a+x+1);
	int last=0,ans=0;
	for(int i=1; i<=x; i++) {
		if(a[i].first>last) {
			ans++;
			last=a[i].second;
		}
	}
	cout<<ans<<endl;
	return 0;
}
