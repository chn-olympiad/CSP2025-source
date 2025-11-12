#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505],c[505];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n) {
		int flag=0;
		for(int i=1; i<=n; i++) {
			cin>>a[i];
			if(a[i]==0) flag=1;
		}
		for(int i=1; i<=n; i++) {
			cin>>c[i];
			if(c[i]==0) flag=1;
		}
		if(flag==1) cout<<0<<endl;
		else cout<<1<<endl;
	}
	cout<<0<<endl;
	return 0;
}
