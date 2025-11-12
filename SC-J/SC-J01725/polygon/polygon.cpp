#include<bits/stdc++.h>
using namespace std;
int a[5010];
int jg(int syh,int syd,int jbx,int sd,int i) {
	sd-=1;
	int ans=0;
	if(sd==0) {
		for(int j=i+1; j<=jbx; j++) {
			if(syh+a[j]>2*max(syd,a[j])) ans++;
		}
		return ans;
	}
	for(int j=i+1; j<=jbx-sd; j++) {
		ans+=jg(a[j]+syh,max(syd,a[j]),jbx,sd,j);
	}
	return ans;
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(n==3) {
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])) cout<<1;
		else cout<<0;
	} else {
		long long ans=0;
		for(int i=3; i<=n; i++) {
			ans+=jg(0,-1,n,i,0);
			ans%=998244353;
		}
		cout<<ans;
	}
	return 0;
}