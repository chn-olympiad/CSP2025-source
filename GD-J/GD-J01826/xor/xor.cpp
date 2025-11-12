#include<bits/stdc++.h>
using namespace std;
int cnt=1;
int n,k,a[500010],ans;
struct node {
	int l,r,lon;
} p[500010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		int sum=a[i];
		for(int j=i; j<=n; j++) {
			if(j!=i) {
				sum^=a[j];
			} else;
			if(sum==k) {
				p[cnt].l=i,p[cnt].r=j;
				p[cnt++].lon=j-i+1;
				break;
			}
		}
	}
	for(int i=1; i<cnt; i++) {
		int sum=0;
		int l,r,mid;
		for(int j=i; j<cnt; j=l) {
			sum++;
			l=j,r=cnt;
			while(l<r) {
				mid=l+r>>1;
				if(p[mid].l<=p[j].r) {
					l=mid+1;
				} else r=mid;
			}
		}
		ans=max(ans,sum);
	}
	cout<<ans<<endl;
	return 0;
}
