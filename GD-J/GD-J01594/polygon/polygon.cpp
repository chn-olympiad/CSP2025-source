#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N+1];
long long c(int n,int m){
	long long ans=1;
	if(m>n/2){
		m=n-m;
	}
	if(m==0) return 1;
	int try_now=m;
	for(int i=n;i>=n-m+1;i--){
		ans*=i;
		while(ans%try_now==0&&try_now>1){
			ans/=try_now;
			try_now--;
		}
//		cerr<<ans<<endl;
	}
	return (long long)ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
//	freopen("test.err","w",stderr);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	cerr<<c(500,250);
	int n;
	cin>>n;
	int max_a=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a,a[i]);
	}
	if(max_a==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
		}
		cout<<ans;
	}
	else if(n<=5000){
//		cerr<<"YES";
		long long ans=0;
		for(long long i=5;i<=((1<<n)-1);i++){
			long long sum=0;
			int max_j=0;
			for(int j=1;j<=n;j++){
				sum+=a[j]*(i>>(j-1)&1);
				if(i>>(j-1)&1&&a[j]>a[max_j]){
					max_j=j;
				}
			}
//			cerr<<i<<" "<<sum<<" "<<a[max_j]<<endl;
			if(sum>a[max_j]*2){
				ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

