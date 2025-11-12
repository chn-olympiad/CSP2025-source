#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5000+5]; 
long long f[5000+5];
void fd(long long i,long long sum,long long maxn) {
	sum+=a[i];
	if(sum>maxn) {
		//cout<<"Iget";
		ans++;
	}
	for(long long j=i-1;j>=1;j--) {
		//cout<<j<<" "<<sum<<" "<<maxn<<'\n';
		fd(j,sum,maxn);
	}
	
}
int main() {
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long i;
	for(i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) {
		f[i]=f[i-1]+a[i];
	}
	long long k,j;
	for(i=3;i<=n;i++) {
		for(j=i-1;j>=2;j--) {
			fd(j,0,a[i]);
		}
	}
	cout<<ans;
	return 0;
}