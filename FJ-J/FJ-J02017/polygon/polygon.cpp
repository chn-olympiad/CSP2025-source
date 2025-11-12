#include<bits/stdc++.h>
using namespace std;
const int N = 5010;
int n;
long long ans;
long long a[N],sum[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]+=sum[i-1]+a[i];
	}
	if(n==3){
		if(2*a[n]<sum[n])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			if(sum[j]-sum[i-1]>2*a[j])ans++;
		}
	}
	cout<<ans;
	return 0;
}
