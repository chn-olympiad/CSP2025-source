#include <iostream>
#include <algorithm>
using namespace std;

int a[5005]= {};

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	int ans=0,mx=0;
	if(n==3) {
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			ans+=a[i];
			mx=max(a[i],mx);
		}
		if(ans>2*mx) {
			cout<<1<<endl;
		} else {
			cout<<0<<endl;
		}
	} else {
		for(int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int cnt=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				ans+=a[i];
				mx=max(a[i],mx);
				if(ans>2*mx){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
