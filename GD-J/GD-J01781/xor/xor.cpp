#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
long long n,m;
long long a[maxn];
long long sum=0;
long long xxor(long long ans2,long long ans3) {
	long long ans11=ans2^ans3;
	return ans11;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long long  i=1; i<=n; i++) {
		long long ss=a[i];
		if(ss==m) {
			sum++;
			continue;
		}
		for(long long j=i+1; j<=n; j++) {
			ss=xxor(ss,a[j]);
			if(ss==m) {
				i=j;
				sum++;
				break;
			} else if(j==n) {
				break;
			}

		}
	}
	cout<<sum;
	return 0;
}
