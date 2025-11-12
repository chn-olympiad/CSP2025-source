#include<bits/stdc++.h>
using namespace std;
long long n,m,k,x,a[70555],t;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>x;cin>>x;cin>>x;
		a[i]=x;
	}
	for(int i=1;i<=k;i++){
		cin>>t;
		for(int i=1;i<=n;i++){
			cin>>x;
		}
		a[i+m]=x+t;
	}
	sort(a+1,a+1+m+k);
	for(int i=1;i<n;i++){
		x+=a[i];
	}
	cout<<x;
	fclose(stdin);
	fclose(stdout);

	return 0;
}
