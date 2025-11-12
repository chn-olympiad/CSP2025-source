#include<bits/stdc++.h>
using namespace std;
long long ans,n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]>1) flag=0;
	}
	if(flag&&k<=1){
		if(k==1){
			int sum=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) sum++;
			}
			cout<<sum;
		}
		else{
			int sum=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
				else{
					sum++;
					sum+=cnt/2;
					cnt=0;
				}
			}
			if(cnt>0) sum+=cnt/2;
			cout<<sum;
		}
		return 0;
	}
	if(flag&&k>1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long r=i,s=0,sum=0;
		while(r<=n){
			sum^=a[r];
			if(sum==k){
				s++;
				sum=0;
			} 
			r++;
		}
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}
