#include<bits/stdc++.h>
using namespace std;
int n,m,s,ss,ans=1;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<n*m; i++) {
		cin>>ss;
		if(s<ss)ans++;
	}
	cout<<(ans-1)/m+1;
	if((ans-1)/m+1==0) {
		cout<<' '<<n-ans%n+1;
	} else cout<<' '<<(ans-1)%n+1;
	return 0;
}

