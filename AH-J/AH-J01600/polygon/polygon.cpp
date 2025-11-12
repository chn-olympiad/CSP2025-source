#include<bits/stdc++.h>
using namespace std;
int n,ans,a[25],p=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	if(n<3) cout<<0<<endl;
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3]) ans++;
	}
	if(n==4){
		if(a[4]*2<sum) ans++;
		for(int i=1;i<=n;i++){
			int mx=a[4];
			if(i==n) mx=a[3];
			sum-=a[i];
			if(mx*2<sum) ans++;
		}
	}
	cout<<ans<<endl;
}
