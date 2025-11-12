#include<bits/stdc++.h>

using namespace std;

int n,m,sum,a[1005],r,p;

int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+sum+1,greater<int>());
	for(int i=1;i<=sum;i++)
		if(a[i]==r) {
			p=i;
			break;
		}
	int cnt=0;
	for(int i=1;i<=m;i++) {
		if(i&1) {
			for(int j=1;j<=n;j++) {
				cnt++;
				if(cnt==p) return cout<<i<<' '<<j,0;
			}
		}
		else {
			for(int j=n;j>=1;j--) {
				cnt++;
				if(cnt==p) return cout<<i<<' '<<j,0;
			}
		}
	}
	return 0;
}
