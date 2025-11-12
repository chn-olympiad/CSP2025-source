#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt1,cnt2,cnt,ans=INT_MIN;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool f=0;
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]>1) f=1;
	}
	for(long long i=1; i<=n; i++) {
		cnt1=a[i];
		for(long long j=i; j<=n; j++) {
			cnt=1;
			if(i!=j) cnt1=(cnt1^a[j]);
			for(long long k=j+1; k<=n; k++) {
				if(cnt1!=m) break;
				if(k==j+1) cnt2=a[k];
				else cnt2=(cnt2^a[k]);
//				cout<<i<<" "<<j<<" "<<cnt2<<endl;
				if(cnt2==cnt1) {
					cnt2=0;
					cnt++;
					ans=max(ans,cnt);
				}
			}
		}
	}
	long long q=1;
	cout<<max(q,ans);
	return 0;
}
