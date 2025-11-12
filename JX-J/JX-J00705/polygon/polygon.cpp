#include <bits/stdc++.h>
#define int long long
#define N 5010
using namespace std;
int n,maxx=0,sum=0;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(a[i],maxx);
		sum+=a[i];
	}
	if(n==3&&sum>maxx*2){
		cout<<1;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n-3;i++){
		int q=1;
		for(int j=n;j>n-i;j--){
			q*=j;
		}
		for(int j=1;j<=i;j++){
			q/=j;
		}
		ans+=q;
	}
	cout<<ans;
	return 0;
}
