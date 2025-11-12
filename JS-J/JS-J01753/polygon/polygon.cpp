#include<bits/stdc++.h>
using namespace std;
int a[100005],n;
void solve(){
	long long sum=0;;
	for(int i=3;i<=n;i++){
		long long ans=1;
		for(int j=n;j>=n-i+1;j--)ans*=j;
		for(int j=1;j<=i;j++)ans/=j;
		sum+=ans;
	}
	cout << sum << '\n';
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int ans=0,maxm=-1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		maxm=max(maxm,a[i]);
	}
	if(maxm==1){
		solve();
		return 0;
	}
	for(int i=1;i<(1<<n);i++){
		int sum=0,maxn=-1,cnt=0;
		for(int j=0;j<n;j++){
			if(((1<<j)&i)!=0){
				cnt++;
				sum+=a[j];
				maxn=max(maxn,a[j]);
			}
		}
		if(sum>maxn*2&&cnt>=3)ans=(ans+1)%998244353;
	}
	cout << ans << '\n';
	return 0;
}
