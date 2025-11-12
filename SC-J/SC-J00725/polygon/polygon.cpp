#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n;
	cin>>n;
	vector<long long> a(n+1);
	vector<long long> qw(n+1);
	bool po=1;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=0)po=0;
	}
	if(po){
		long long ans=0;
		long long ll=1;
		for(int j=2;j<n;j++){
			ll=1;
			for(int i=n-j;i>=0;i++){
				ans+=i*ll;
				ans%=998244353;
				ll++;
			}
		}
		cout<<ans;
		return 0;
	}
	long long ans=0;
	long long mx=0;
	long long mm=0;
	sort(a.begin(),a.end());
	for(long long i=n-1;i>=0;i--){
		qw[i]=qw[i-1]+a[i];
	}
	for(long long i=n-1;i>=0;i--){
		if(a[i]*2>=qw[0])continue;
		for(long long j=0;j<i;j++){
			if(a[i]*2>=qw[j])break;
			for(long long k=j+1;k<n;k++){
				if(qw[j]-a[k]>a[i]*2){
					long long op=qw[j]-a[k];
					for(long long l=k+1;l<n;l++){
						if(op-a[l]>a[i]*2){
							ans++;
							ans%=998244353;
							op-=a[l];
						}
						else {
							op+=a[l];
						}
					}
				}
			}
		}
	}
//	for(int i=0;i<n;i++){
//		mm=a[i];
//		mx=a[i];
//		for(int j=i+1;j<n;j++){
//			mm+=a[j];
//			mx=max(a[j],mx);
//			for(int k=j+1;k<n;k++){
//				mm+=a[k];
//				mx=max(a[k],mx);
//				for(int l=k+1;l<n;l++){
//					mx=max(mx,a[l]);
//					mm+=a[l];
//					if(mm>mx*2){
//						ans++;
//						ans%=998244353;
//					}
//					else if(mx==a[l]){
//						mm-=a[l];
//					}
//				}
//				
//				mm-=a[k];
//			}
//			mm-=a[j];
//		}
//	}
	cout<<ans;
	return 0;
}