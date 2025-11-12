#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=3;i<=n;i++){
		long long a=1,b=1,c=1;
		for(int j=2;j<=n;j++){
			a*=j;
			a%=998244353;
		}
		for(int k=2;k<=i;k++){
			b*=k;
			b%=998244353;
		}
		for(int l=2;l<=n-i;l++){
			c*=l;
			c%=998244353;
		}
		ans+=a/b/c;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}

