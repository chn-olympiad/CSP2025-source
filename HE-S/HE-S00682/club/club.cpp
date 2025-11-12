#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100005],b[100005],c[100005];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		sort(c+1,c+1+n);
		int ans=max(a[n]+b[n],a[n]+c[n]);
		ans=max(ans,c[n]+b[n]);
		cout<<ans<<endl;
	}
	return 0;
}
