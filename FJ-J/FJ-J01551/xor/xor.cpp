#include<bits/stdc++.h>
using namespace std;
int yh=0;
int n,k,a[1000005],cnt;
bool b[1000005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	int m=1;
	while(m<=n) {
		for(int i=1; i<=n-m+1; i++) {
			yh=0;
			for(int j=i; j<=m+i-1; j++) {
				if(b[j]==1)yh-=100;
				yh^=a[j];
			}
			if(yh==k) {
				for(int j=i; j<=m+i-1; j++) {
					b[j]=1;
				}
				yh=0;
				cnt++;
			}
		}
		m++;
	}
	cout<<cnt;
	return 0;
}
