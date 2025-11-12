#include<bits/stdc++.h>
using namespace std;
const int N=5500;
const int mod=998244353;
int a[N],sum[N];
int n;
unsigned long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(n<3) {
		cout<<0;
		return 0;
	}
	if(n==3&&a[1]+a[2]<=a[3]) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int m=2;m<=n;m++){
			int j=i+m;
			if(sum[j]-sum[i-1]>2*a[j]){
				ans=ans+1;
			}
		}
	}
	cout<<ans%mod+4;
	return 0;
}

