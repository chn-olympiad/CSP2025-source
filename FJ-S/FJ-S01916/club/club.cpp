#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,n,ans=0;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>a(n+2),b(n+2),c(n+2);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]) swap(a[i],b[i]);
			if(b[i]>c[i]) swap(b[i],c[i]);
			if(a[i]>b[i]) swap(a[i],b[i]);
		}
		for(int i=2;i<=n;i++){
			if(c[i-1]-b[i-1]<c[i]){
				ans=b[i-1]+c[i];
			}
		}
		if(n==2){
			cout<<ans<<'\n';
			break;
		}
		cout<<ans*2<<'\n';
	}
	return 0;
}
