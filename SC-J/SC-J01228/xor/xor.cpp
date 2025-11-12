#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],maxx=0,x[500005],z=1,p;
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			maxx++;
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			long long ans=a[i];
			for(long long l=i+1;l<=j;l++){
				ans=ans^a[l];
			}
			if(ans==k){
				x[i]++;
				x[j]++;
				if(x[i]>=2||x[j]>=2){
					p=1;
				}
				z++;
			}
		}
	}
	if(p==0){
		cout<<max(maxx,z)<<endl;
	}else{
		long long maxxx=0;
		for(long long i=1;i<=n;i++){
			if(x[i]>=2){
				maxxx+=x[i]-1;
			}
		}
		maxxx/=2;
		int jdk_=max(maxx,(z-maxxx));
		cout<<jdk_;
	}
	return 0;
}