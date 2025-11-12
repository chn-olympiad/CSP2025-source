#include<bits/stdc++.h>
using namespace std;
long n,k,a[900010],cnt=0,t,r;
bool c;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	r=n;
	for(long i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(long i=1; i<=n; i++) {
		t=0;
		for(long j=i; j<=r; j++) {
			t^=a[j];
			if(t==k) {
				c=true;
				r=j;
				break;
			}
		}
		if(i>=r&&c==true) {
			c=false;
			cnt++;
			r=n;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
