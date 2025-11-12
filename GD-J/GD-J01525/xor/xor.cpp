#include<bits/stdc++.h>
using namespace std;
long long a[1000100],b[1000010];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	long long n,k1;
	cin>>n>>k1;
	long long sum = 0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i] = 1;
	}

	long long l =1,r = 1,num;
	bool er = 0;
	for(long long i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(b[i] == 1) {
				num = a[i];
				er = 0;
			} else continue;
			for(long long k = i+1; k<=j; k++) {
				if( b[k] == 1)num = num xor a[k];
				else {
					er = 1;
					break;
				}
			}
			r++;
			if(num == k1 ) {
				sum++;
				for(long long k=i; k<=j; k++) b[k] = 0;
				//cout<<i<<" "<<j<<"\n";
			}
		}
		l++;
	}
	cout<<sum;
	return 0;
}

