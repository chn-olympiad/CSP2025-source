#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,m,a[100005]={},b[100005]={},c[100005]={},id=0,ans=0;
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+n);
		for(int i=n;i>=m+1;i--){
			ans+=a[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
