#include<bits/stdc++.h>
using namespace std;
int main() {
	int m,n;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	long long b[10000];
	int h=0;
	n=0;
	int ans;
	for(int i=1; i<n*m; i++) {
		cin>>b[i];
		if(b[0]<b[i]) {
			ans++;
		} else if(b[0]>b[i]) {
			ans=ans;
		}
	}
	cout<<ans;
	return 0;
}
