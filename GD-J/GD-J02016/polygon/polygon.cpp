#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=3;i<=n;i++){
		if(sum[i]>2*a[i-1])ans++;
	}
	cout<<ans;
	return 0;
}
