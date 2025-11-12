#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans,s;
int a[500005],b[500005];
int x[500005],y[500005];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (i==1) b[i]=a[i];
		else b[i]=b[i-1]^a[i];
		for (int j=i;j>=1;j--) {
			if ((b[i]^b[j-1])==k) {
				s++;
				x[s]=i;
				y[s]=j;
				break;
			}
		}
	}
	int num=0;
	for (int i=1;i<=s;i++) {
		if (y[i]>num) {
			ans++;
			num=x[i]; 
		}
	}
	cout<<ans<<endl;
	return 0;
} 
