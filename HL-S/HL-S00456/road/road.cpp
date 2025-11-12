#include<bits/stdc++.h>
using namespace std;
long long n,m,k,ans;
long long w[1000003];
long long c[10003];
long long a[10003][13];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		long long u,v;
		cin>>u>>v>>w[i];
		if(i%2==1) ans+=w[i];
	}
	for(int j=1;j<=k;j++) {
		cin>>c[j];
//		cout<<"YYYYY"<<endl;
		for(int o=1;o<=n;o++) {
			cin>>a[j][o];
		}
	}
	cout<<ans<<endl;
	return 0;
}
